#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"

RF24 radio(7, 8); //Arduino UNO
// #include <Servo.h>

// #define D10 10
// #define D2 5

// Servo servo;

void setup() {
  Serial.begin(9600);
  Serial.println("Scanner Air On");
  printf_begin();
  radio.begin();
  radio.setAutoAck(false);

  radio.startListening();
  radio.printDetails();
  delay(5000);
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   servo.attach(D10);
}

// int angle = 0;

// int yPos = 0;
const int num_reps = 100;

const uint8_t num_channels = 128;
uint8_t values[num_channels];

bool test_channel(int channel) {
  radio.setChannel(channel);

  // Listen for a little
  radio.startListening();
  delayMicroseconds(1024);
  radio.stopListening();
  
  return radio.testCarrier();
}

void loop() {
  Serial.println("Start scanning");
  memset(values, 0, sizeof(values));
  int rep_counter = num_reps;
  while(rep_counter--) {
    int channel = num_channels;
    while(channel--) {
      if (test_channel(channel)) {
        ++values[channel];
      }
    }
  }
  for (int i = 0; i < num_channels; i++) {
    if (values[i] == 0) {
      continue;
    }
    Serial.print("Channel: ");
    Serial.print(i);
    Serial.print(" result: ");
    Serial.println(values[i]);
  }
  delay(50000);
//   yPos = analogRead(A0);
//   angle = map(yPos, 0, 1023, 0 ,180);
//   servo.write(angle);
}
