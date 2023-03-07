#include <SPI.h>
#include <LoRa.h>

#define FREQ 915E6

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa receiver");
  if (!LoRa.begin(FREQ)) {
    Serial.println("LoRa initialization failed");
    while (true) delay(1000);
  }
}

void loop() {
  if (!LoRa.parsePacket()) return;

  Serial.print("Received packet '");
  while (LoRa.available()) Serial.print((char) LoRa.read());
  Serial.print("' with RSSI ");
  Serial.println(LoRa.packetRssi());
}