#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


//----ISTIHAR GPIO PIN anda kumpulkan disini ---------------------------------------------------------------------------------


//---=on board------
#define oneWireBus 15  //--SENSOR SUHU DS18B20
#define Relay01 27   //relay 1
#define Relay02 26   // relay 2
#define buzzer  2     // Buzzer
//--- device/sensor OFF board ------
#define sensorIRed  36
#define AnalogSensor2  35
#define temtLightSensor 39


#define ESPADC 4096.0   //the esp Analog Digital Convertion value
#define ESPVOLTAGE 3300 //the esp voltage supply value
#define PH_PIN 36   //the esp gpio data pin number
float voltage, phValue, temperature=25;


//----ISTIHAR LCD I2C --------------------------------------------------------------
LiquidCrystal_I2C lcd(0x27,20,4);


//----ISTIHAR SENSOR SUHU DS18B20 ---------------------------------------------------------------------
 
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);
//----------------------------------- end -------------------------------------------------------------

//---- PEMBOLEHUBAH DATA---------------------------------------------------------------------------------


float light;

//----------------------------------- end ---------------------------------------------


void setup() {
  pinMode (Relay01,OUTPUT);
  pinMode (Relay02,OUTPUT);
  pinMode (buzzer,OUTPUT);

  delay(100);
  digitalWrite(Relay01,LOW);
  digitalWrite(Relay02,LOW);
  digitalWrite(buzzer,LOW);
    
   
  Serial.begin(115200);
  sensors.begin();
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("System is starting..");
  digitalWrite(buzzer,HIGH);
  delay(500);
  digitalWrite(buzzer,LOW);
  delay(500);

  lcd.setCursor(0,1);
  lcd.print("ESP32 PROJECT BOARD ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("   KOLAM IoT 2023   ");
}


void loop() {
 
    sensors.requestTemperatures(); // Send the command to get temperatures
    float tempC = sensors.getTempCByIndex(0);
    Serial.print("Sensor suhu : ");
    Serial.println(tempC);
  
    lcd.setCursor(0,1);
    lcd.print("suhu: ");
    lcd.setCursor(6,1);
    lcd.print(tempC,1);

  int dataIR = analogRead(sensorIRed);
  Serial.print("paras IR : ");
  Serial.println(dataIR);

  lcd.setCursor(0,2);
  lcd.print("IR: ");
  lcd.setCursor(8,2);
  lcd.print(dataIR);
  
}
