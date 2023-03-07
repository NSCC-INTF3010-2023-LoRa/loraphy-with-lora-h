#include <SPI.h>
#include <LoRa.h>

#define FREQ 915E6

int count = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa sender");
  if (!LoRa.begin(FREQ)) {
    Serial.println("LoRa initialization failed");
    while (true) delay(1000);
  }
}

void loop() {
  Serial.print("Sending packet #");
  Serial.println(count);

  LoRa.beginPacket();
  LoRa.print("Hello #");
  LoRa.print(count);
  LoRa.endPacket();

  count++;
  delay(5000);
}