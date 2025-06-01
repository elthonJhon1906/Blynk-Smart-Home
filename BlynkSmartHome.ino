#define BLYNK_TEMPLATE_ID "TMPLmcTdmYS-"
#define BLYNK_DEVICE_NAME "kontrol relay"
#define BLYNK_AUTH_TOKEN "4FmqtfWvA_sv4WipwIW-mrvtdrlQXhWp"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "4FmqtfWvA_sv4WipwIW-mrvtdrlQXhWp";
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

BlynkTimer timer;
#define relay 2
int SW_relay = 0;

BLYNK_WRITE(V0)
{
  SW_relay = param.asInt();
  if (SW_relay ==1){
    digitalWrite(relay, HIGH);
    Serial.println("Relay terbuka");
    Blynk.virtualWrite(V0, HIGH);
  }else{
    digitalWrite(relay, LOW);
    Serial.println("Relay tertutup");
    Blynk.virtualWrite(V0, LOW);
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();
}
