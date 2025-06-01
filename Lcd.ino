#include <DHT.h> 
#include <LiquidCrystal_I2C.h> 
#include <Wire.h> 
#define DHTPIN 8 
#define DHTTYPE DHT22 
DHT dht (DHTPIN, DHTTYPE); 
LiquidCrystal_I2C lcd(0x27, 16, 2);  
 
void setup() { 
  // put your setup code here, to run once: 
  lcd.backlight(); 
  Serial.begin(9600); 
  dht.begin();  
  Serial.println("Praktikum Embedded Systems"); 
  Serial.println("LAB TEKNIK DIGITAL"); 
  lcd.init(); 
  int positionCounter;  
  lcd.setCursor(2,0); 
  lcd.print("Praktikum Embedded Systems"); 
  lcd.setCursor(2,1); 
  lcd.print("LAB TEKNIK DIGITAL"); 
  for(positionCounter = 0; positionCounter < 26; positionCounter++){ 
  lcd.scrollDisplayLeft(); 
  delay (300);} 
  lcd.clear(); 
}

void loop() { 
// put your main code here, to run repeatedly: 
  float t = dht.readTemperature(); 
  float h = dht.readHumidity(); 
  Serial.print("Suhu : "); 
  Serial.print(t); 
  Serial.println("°C"); 
  Serial.print("Kelembapan : "); 
  Serial.print(h); 
  Serial.println("%"); 
  lcd.setCursor(0,0); 
  lcd.print("Suhu : "); 
  lcd.print(t);; 
  lcd.setCursor(0,1); 
  lcd.print("Kelembapan: "); 
  lcd.print(h); 
   delay(1000); 
}