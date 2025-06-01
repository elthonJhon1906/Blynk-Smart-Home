#include <DHT.h> 
#include <LiquidCrystal_I2C.h> 
#include <Wire.h> 

#define DHTPIN 7 
#define soilMoisture A0
#define buzzer 8
#define relayPin 10
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE); 
LiquidCrystal_I2C lcd(0x27, 16, 2);  

void setup() { 
  lcd.backlight(); 
  Serial.begin(9600); 
  dht.begin();  
  lcd.init(); 
  lcd.clear(); 

  pinMode(buzzer, OUTPUT);
  pinMode(relayPin, OUTPUT);
}

void loop() { 
  float t = dht.readTemperature(); 
  float h = dht.readHumidity(); 
  int soilValue = analogRead(soilMoisture);
  soilValue = map(soilValue, 10, 550, 100, 0); // adjusted mapping

  Serial.print("Suhu : "); Serial.print(t); Serial.println("°C"); 
  Serial.print("Kelembapan : "); Serial.print(h); Serial.println("%"); 
  Serial.print("Moisture : "); Serial.print(soilValue); Serial.println("%");

  lcd.setCursor(0, 0); 
  lcd.print("Suhu: "); lcd.print(t); lcd.print("C "); 
  lcd.setCursor(0, 1); 
  lcd.print("Moist: "); lcd.print(soilValue); lcd.print("%");

  if (soilValue < 20 && t > 25) {
    tone(buzzer, 1000);
    digitalWrite(relayPin, LOW); // aktifkan relay
    delay(1000);
    noTone(buzzer);
    delay(3000);
  } else {
    digitalWrite(relayPin, HIGH); // matikan relay
  }

  delay(1000);
}