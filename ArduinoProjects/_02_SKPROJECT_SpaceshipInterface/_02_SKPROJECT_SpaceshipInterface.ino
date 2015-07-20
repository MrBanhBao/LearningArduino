int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT); //digitalReader
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);
  
  if(switchState == 0){ //Switch is not been pushed
    
    digitalWrite(3, HIGH); // Green LED
    digitalWrite(4, LOW); //Red LED
    digitalWrite(5, LOW); //Red LED
    
  }else{ //  Switch has been pushed
    
    digitalWrite(3, LOW); 
    
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    
    delay(250);
    
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    
    delay(250);
  }
  
}
