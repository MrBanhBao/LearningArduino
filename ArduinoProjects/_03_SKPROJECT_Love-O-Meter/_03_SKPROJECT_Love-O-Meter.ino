const int sensorPin = A0; //assign constant "sensorPin" with value A0
const float baselineTemp = 18.0; //Threshold

void setup() {
  Serial.begin(9600); //open serial port (connection from PC to Arduino) with 9600bits per second
  
  //assign OutputPins(LEDs) with the help of the for-loop
  for(int pinNumber = 2; pinNumber < 5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW); //No flow
  }
}

void loop() {
  
  int sensorVal = analogRead(sensorPin); //sensorVal stores Value of the Sensor
  //Prints sensorVal
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  
  //Convert analog datas to voltage
  float voltage = (sensorVal/1024.0)*5.0;
  //Print voltage
  Serial.print(", Volts: ");
  Serial.print(voltage);
  
  //Convert Voltage into Celcius
  float temperature = (voltage - .5) * 100;
  Serial.print(", degrees C: ");
  Serial.println(temperature); //Last thing to print -> println
  
  
  if(temperature < baselineTemp){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp + 2 && temperature < baselineTemp + 4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp + 4 && temperature < baselineTemp + 6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp + 6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  delay(1);
  
}
