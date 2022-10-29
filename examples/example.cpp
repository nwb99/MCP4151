#include <Arduino.h>
#include <MCP4151.h>

#define CS     10
#define MOSI   11
#define MISO   12
#define SCK    13

MCP4151 pot(CS, MOSI, MISO, SCK);
// MCP4151 pot(CS, MOSI, MISO, SCK, 4000000, 250000, SPI_MODE0);

void setup() {
  pot.writeValue(0); // turn the pot off
  Serial.begin(9600);
}

void loop() {
  /*
  can connect a 5V LED in series with like a 330 Ohm resistor to pin 6 (P0W)
  on the MCP4151. This should cause a "breathing" LED effect.
  Furthermore, 'pot.getCurValue()' is reading the value from the IC.
  The chip stores the wiper as an 8-bit value at address 00h.
  Valid values are 0-255 (or 0x0 to 0xFF, if you prefer).
  For my test LED, 87 was basically 'off', given the voltage was too low.
  */
  int i = 87;
  while (i <= 254) {
    pot.writeValue(i);
    Serial.println(pot.getCurValue());
    delay(100);
    i += 3;
  }
  while (i >= 87) {
    pot.writeValue(i);
    Serial.println(pot.getCurValue());
    delay(100);
    i -= 3;
  }
}