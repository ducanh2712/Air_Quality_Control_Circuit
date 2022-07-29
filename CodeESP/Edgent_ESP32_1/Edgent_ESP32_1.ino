// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLNTE_sKQt"
#define BLYNK_DEVICE_NAME "BTL"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG
#define APP_DEBUG
#define RXD2 16
#define TXD2 17
#include "BlynkEdgent.h"


int ledpin =13;
int bellpin = 12;
BLYNK_WRITE(V0){
  int pinValue= param.asInt();
  digitalWrite(ledpin,pinValue);
}
BLYNK_WRITE(V5){
  int pinValue= param.asInt();
  digitalWrite(bellpin,pinValue);
}



void setup()
{
  Serial.begin(115200);
//  Serial2.begin(1200, SERIAL_8N1, RXD2, TXD2);
  delay(100);
  
  pinMode(ledpin,OUTPUT);
  pinMode(bellpin,OUTPUT);
  BlynkEdgent.begin();

  
}

void loop() {
  BlynkEdgent.run();

}
