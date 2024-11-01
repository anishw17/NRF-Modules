// Code by Anish Walke...!
// Transmitter code!
#include <RF24.h>
int fs = A0;
RF24 nrft(9,10); // CE and CSN
const byte address[6] = "00001";

void setup()
{
  Serial.begin(9600);
  nrft.begin();
  nrft.openWritingPipe(address);
  nrft.setPALevel(RF24_PA_MIN);
  nrft.stopListening();
}

void loop()
{
  int sv = analogRead(A0);
  Serial.print("Sensor value : ");
  Serial.println(sv);
  nrft.write(&sv, sizeof(sv));
  delay(1000);
}