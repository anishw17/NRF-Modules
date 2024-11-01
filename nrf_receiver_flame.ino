// Code by Anish Walke...!
// Receiver Code!
#include <RF24.h>

int b = 4;
RF24 nrfr (9,10); // CE and CSN
const byte address[6] = "00001";

void setup()
{
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  nrfr.begin();
  nrfr.openReadingPipe(1,address);
  nrfr.setPALevel(RF24_PA_MIN);
  nrfr.startListening();
}

void loop()
{
  if (nrfr.available())
  {
    int sv;
    nrfr.read(&sv,sizeof(sv));
    Serial.print("Received sensor value :");
    Serial.println(sv);
    if (sv < 1000)
    {
      digitalWrite(4,HIGH);
    }
    else if(sv > 1000)
    {
      digitalWrite(4,LOW);
    } 
    delay(1000);
  }
}