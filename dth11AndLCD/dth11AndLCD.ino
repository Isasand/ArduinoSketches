#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT;

#define DHT11_PIN 7

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop()
{
  lcd.setCursor(0,0);
  int chk = DHT.read11(DHT11_PIN);
  lcd.print("Temp: ");
  lcd.print(DHT.temperature,1 );
  lcd.print(" oC");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity, 1);
  lcd.print("%");
  delay(1000);
}
