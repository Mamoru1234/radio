#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"

RF24 radio(7, 8); //Arduino UNO

const byte server[5] = {'R', 'x', 'A', 'T', 'B'}; 

void setup() {
  Serial.begin(9600);
  Serial.println("Sender On");
  printf_begin();
  radio.begin();
  delay(3000);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setCRCLength(RF24_CRC_8);
  radio.setPALevel(RF24_PA_MIN);
  radio.setChannel(60);
  radio.stopListening();
  radio.powerUp();
  radio.printDetails();
  radio.openWritingPipe(server);
  Serial.println("Start send...");
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   servo.attach(D10);
}

uint8_t data;
int y_inp;

void loop() {
  y_inp = analogRead(A0);
  data = map(y_inp, 0, 1024, 0, 180);
  radio.write(&data, 1);
  delay(24);
}