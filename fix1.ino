#include <DHT.h> 
#include <LiquidCrystal_I2C.h> 
#include <Wire.h> 
#define DHTPIN 7 
#define soilMoisture A0
#define buzzer 8
#define relayPin 10
#define DHTTYPE DHT11 
DHT dht (DHTPIN, DHTTYPE); 
LiquidCrystal_I2C lcd(0x27, 16, 2);  
 
void setup() { 
  // put your setup code here, to run once: 
  lcd.backlight(); 
  Serial.begin(9600); 
  dht.begin();  
  lcd.init(); 
  lcd.clear(); 
}

void loop() { 
// put your main code here, to run repeatedly: 
  float t = dht.readTemperature(); 
  float h = dht.readHumidity(); 
  int soilValue = analogRead(soilMoisture);
  soilValue = map(soilValue, 550, 10, 0, 100);

  Serial.print("Suhu : "); 
  Serial.print(t); 
  Serial.println("°C"); 
  Serial.print("Kelembapan : "); 
  Serial.print(h); 
  Serial.println("%"); 
  lcd.setCursor(0,0); 
  lcd.print("Suhu : "); 
  lcd.print(t);
  lcd.setCursor(0,1); 
  lcd.print("Kelembapan: "); 
  lcd.print(h); 
  delay(2000); 
  lcd.clear();
  lcd.setCursor(0,1); 
  lcd.print("Mositure : ");
  lcd.print(soilValue);
  if(soilValue < 20 && t > 25) {
  tone(buzzer, 1000);
  digitalWrite(relayPin, LOW);
  delay(1000);
  noTone(buzzer);
  delay(3000);
  } else {
  digitalWrite(relayPin, HIGH);  
  }
  delay(1000);

}