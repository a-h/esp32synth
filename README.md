# Start of a synth

Reminder of u8x8 features.

```go
u8x8.drawString(0, 0, "square");
u8x8.setCursor(0, 0);
u8x8.print(totalInterruptCounter, DEC);
```

Reminder of settings:

```json
{
    "board": "esp32:esp32:heltec_wifi_kit_32",
    "configuration": "FlashFreq=80,UploadSpeed=921600",
    "port": "/dev/cu.SLAB_USBtoUART",
    "programmer": "AVR ISP",
    "sketch": "esp32_audio.ino",
    "output": "../output"
}
```