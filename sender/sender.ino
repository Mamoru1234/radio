// #include <SPI.h>
// #include "nRF24L01.h"
// #include "RF24.h"
// #include "printf.h"

// RF24 radio(7, 8); //Arduino UNO

// const byte server[5] = {'R', 'x', 'A', 'T', 'B'};

struct Signal {
  uint8_t throttle;
  uint8_t pitch;
  uint8_t roll;
  uint8_t yaw;
};

Signal data;

void reset_data() {
  data.throttle = 127; // Motor Stop (254/2=127)
  data.pitch = 127; // Center
  data.roll = 127; // Center
  data.yaw = 127; // Center
}

void read_data() {
  data.throttle = map(analogRead(A0), 0, 1024, 0, 180);
  data.yaw = map(analogRead(A1), 0, 1024, 0, 180);
  data.pitch = map(analogRead(A2), 0, 1024, 0, 180);
  data.roll = map(analogRead(A3), 0, 1024, 0, 180);
}

// void print_data() {
//   Serial.print("Data: throttle = ");
//   Serial.print(data.throttle);
//   Serial.print(" , yaw = ");
//   Serial.print(data.yaw);
//   Serial.print(" , pitch = ");
//   Serial.print(data.pitch);
//   Serial.print(" , roll = ");
//   Serial.print(data.roll);
//   Serial.println(";");
// }

void setup() {
  Serial.begin(9600);
  Serial.println("Sender On");
  reset_data();
  // printf_begin();
  // radio.begin();
  // delay(3000);
  // radio.setAutoAck(false);
  // radio.setDataRate(RF24_250KBPS);
  // radio.setCRCLength(RF24_CRC_8);
  // radio.setPALevel(RF24_PA_MIN);
  // radio.setChannel(60);
  // radio.stopListening();
  // radio.powerUp();
  // radio.printDetails();
  // radio.openWritingPipe(server);
  // Serial.println("Start send...");
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   servo.attach(D10);
}

void loop() {
  // y_inp = analogRead(A0);
  // data = map(y_inp, 0, 1024, 0, 180);
  // radio.write(&data, 1);
  read_data();
  print_data();
  delay(24);
}