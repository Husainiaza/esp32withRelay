void sensorVar(){

  int dataVar = analogRead(AnalogSensor2);
  Serial.print("Sensor Ambient : ");
  Serial.println(dataVar);

  float ambient = dataVar * 0.0976;// percentage calculation
  Serial.print("peratus intensity : ");
  Serial.println(ambient,1);

  lcd.setCursor(0,2);
  lcd.print("cahaya: ");
  lcd.setCursor(8,2);
  lcd.print(dataVar);
}

void sensorsuhu(void)
{ 
  sensors.requestTemperatures(); // Send the command to get temperatures
  float tempC = sensors.getTempCByIndex(0);
  Serial.print("Sensor suhu : ");
  Serial.println(tempC);
  
  lcd.setCursor(0,1);
  lcd.print("suhu: ");
  lcd.setCursor(6,1);
  lcd.print(tempC,1);


  
}


void sensorIR(){

  int dataIR = analogRead(sensorIRed);
  Serial.print("paras IR : ");
  Serial.println(dataIR);

  //lcd.setCursor(0,2);
  //lcd.print("cahaya: ");
  //lcd.setCursor(8,2);
  //lcd.print(dataVar);

 
}