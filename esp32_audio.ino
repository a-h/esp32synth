#include <U8x8lib.h>

U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/15, /* data=*/4, /* reset=*/16);

// Timer setup.
volatile int interruptCounter;

hw_timer_t *timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR onTimer()
{
  portENTER_CRITICAL_ISR(&timerMux);
  interruptCounter++;
  portEXIT_CRITICAL_ISR(&timerMux);
}

void setup()
{
  u8x8.begin();
  u8x8.setFont(u8x8_font_chroma48medium8_r);

  u8x8.drawString(0, 0, "sine");
  u8x8.setCursor(0, 0);

  // Setup a timer.
  timer = timerBegin(0, 80, true); // 80MHz / 80 = 1,000,000Hz.
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 50, true); // 1,000,000Hz / 50 = 20Khz / 2 = 10Khz
  timerAlarmEnable(timer);
}

uint8_t sine[] = { 127, 151, 174, 195, 214, 229, 240, 247, 250, 247, 240, 229, 214, 195, 174, 151, 127, 103, 80, 59, 40, 25, 14, 7, 5, 7, 14, 25, 40, 59, 80, 103 };
const int sineLength = 32;
volatile int pointer = 0;

void loop()
{
  if (interruptCounter > 0)
  {
    portENTER_CRITICAL(&timerMux);
    interruptCounter = 0;
    pointer++;
    if (pointer > sineLength-1)
    {
      pointer = 0;
    }
    portEXIT_CRITICAL(&timerMux);
  }
  dacWrite(25, sine[pointer]);
}