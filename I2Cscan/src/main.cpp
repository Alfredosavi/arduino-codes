#include <Arduino.h>
#include "Wire.h"
extern "C"
{
#include "utility/twi.h" // twi_writeTo
}

byte start_addr = 8;
byte end_addr = 119;
byte found = 0;

void I2Cscan(byte from_addr, byte to_addr,
             void (*callback)(byte addr, byte result));
void feedback(byte addr, byte result);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  Wire.begin();
  Serial.begin(9600);

  Serial.println("\nI2CScanner!\n");

  Serial.print("Range: ");
  Serial.print(start_addr, DEC);
  Serial.print("-");
  Serial.println(end_addr, DEC);

  I2Cscan(start_addr, end_addr, feedback);

  if (found != 0)
  {
    Serial.println("\naddr found.");
    Serial.print("addr_dec: ");
    Serial.print(found, DEC);
    Serial.print(" or addr_hex: ");
    Serial.println(found, HEX);
  }
  else
    Serial.println("\naddr not found.");
}

void loop()
{
  digitalWrite(LED_BUILTIN, LOW);
  delay(450);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(450);
}

void I2Cscan(byte from_addr, byte to_addr,
             void (*callback)(byte addr, byte result))
{
  byte result_addr = 0;
  byte data = 0;
  for (byte addr = from_addr; addr <= to_addr; addr++)
  {
    result_addr = twi_writeTo(addr, &data, 0, 1, 0);
    callback(addr, result_addr);
  }
}

void feedback(byte addr, byte result)
{
  Serial.print("addr_HEX: ");
  Serial.print(addr, HEX);

  if (result == 0)
  {
    Serial.println(" found!");
    found = addr;
  }
  else
    Serial.println();
}