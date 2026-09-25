// NeoPixel Jewel (7 LEDs) on Arduino UNO R4 WiFi
// Wiring: Jewel IN -> pin 6, 5V -> 5V, GND -> GND
// Library: Adafruit NeoPixel (install via Library Manager)

#include <Adafruit_NeoPixel.h>

#define LED_PIN   6
#define LED_COUNT 7

Adafruit_NeoPixel jewel(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  jewel.begin();
  jewel.setBrightness(50);  // 0-255, keep it low to save your eyes
  jewel.show();             // start with all LEDs off
}

void loop() {
  int ir = analogRead(A0);
  ir = map(ir, 60,700, 0, 255);
  ir = constrain(ir, 0, 255);

  Serial.println(ir);
  lightAllRainbow(ir);
}


///>>>>>>>> EXTRA FUNCTIONS THAT DO STUFF!!!

// 0-255 in, spectrum colour out (red -> yellow -> green -> blue -> back to red)
uint32_t rainbow(uint8_t pos) {
  return jewel.ColorHSV(pos * 256);
}

void lightAllRainbow(uint8_t pos) {
  jewel.fill(rainbow(pos));
  jewel.show();
}

void lightAll(uint8_t r, uint8_t g, uint8_t b) {
  jewel.fill(jewel.Color(r, g, b));
  jewel.show();
}


