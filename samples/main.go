package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

// There are 2π radians in a circle.
var circle = (2 * math.Pi)

// Produce 32 samples.
var samples = float64(32)

// Draw samples of sine wave.
func main() {
	min, max := 5, 250
	step := circle / samples
	var outputs []string
	for v := 0.0; v < circle; v += step {
		normalised := scale(-1, 1, min, max, math.Sin(v))
		outputs = append(outputs, strconv.Itoa(normalised))
	}
	fmt.Println(strings.Join(outputs, ","))
}

func scale(fromMin, fromMax, toMin, toMax int, v float64) int {
	outputRange := float64(toMax - toMin)
	inputRange := float64(fromMax - fromMin)
	return int(((outputRange / inputRange) * (v - float64(fromMin)))) + toMin
}
