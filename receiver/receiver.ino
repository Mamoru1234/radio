#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"
#include <Servo.h>

Servo servo;

RF24 radio(7, 8); //Arduino UNO

const byte server[5] = {'R', 'x', 'A', 'T', 'B'}; 

void setup() {
  Serial.begin(9600);
  Serial.println("Receiver On");
  printf_begin();
  radio.begin();
  delay(3000);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setCRCLength(RF24_CRC_8);
  radio.setPALevel(RF24_PA_MIN);
  radio.setChannel(60);
  radio.powerUp();
  radio.openReadingPipe(1, server);
  radio.startListening();
  servo.attach(10);
  Serial.println("Start receiving...");
}

int counter = 0;
int received = 0;
int failed = 0;
uint8_t data[1];

void loop() {
  while(radio.available()) {
    radio.read(data, 1);
    servo.write(data[0]);
  }
  delay(50);
}