#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 7
#define DHTTYPE DHT11

#define MOTOR_PIN_ENA 9
#define MOTOR_PIN_IN1 10
#define MOTOR_PIN_IN2 11

#define TEMPERATURE_THRESHOLD 29 
#define TEMPERATURE_THRESHOLD1 32 

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(MOTOR_PIN_ENA, OUTPUT);
  pinMode(MOTOR_PIN_IN1, OUTPUT);
  pinMode(MOTOR_PIN_IN2, OUTPUT);

  lcd.init();          // ✅ ONLY THIS
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
}

void loop() {
  delay(2000);

  float temperature = dht.readTemperature();
  if (isnan(temperature)) {
    Serial.println("DHT Error");
    return;
  }

  lcd.setCursor(12, 0);
  lcd.print("    ");   // clear old value
  lcd.setCursor(12, 0);
  lcd.print(temperature);

  lcd.setCursor(0, 1);
  lcd.print("                "); // clear line

  if (temperature > TEMPERATURE_THRESHOLD1) {
    analogWrite(MOTOR_PIN_ENA, 255);
    digitalWrite(MOTOR_PIN_IN1, HIGH);
    digitalWrite(MOTOR_PIN_IN2, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Speed: MAX");
  }
  else if (temperature > TEMPERATURE_THRESHOLD) {
    analogWrite(MOTOR_PIN_ENA, 120);
    digitalWrite(MOTOR_PIN_IN1, HIGH);
    digitalWrite(MOTOR_PIN_IN2, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Speed: MED");
  }
  else {
    analogWrite(MOTOR_PIN_ENA, 60);
    digitalWrite(MOTOR_PIN_IN1, HIGH);
    digitalWrite(MOTOR_PIN_IN2, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Speed: LOW");
  }
}