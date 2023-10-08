int redbulb = 13;
int greenbulb = 11;
int buzzer = 8;
int smokeA0 = A5;
// My threshold value
int sensorThres = 200 ;

  #include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);
  

void setup() {
  pinMode(redbulb, OUTPUT);
  pinMode(greenbulb, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);

  mySerial.begin(9600);
  Serial.begin(9600);
  delay(100);
}

void loop() {
  int analogSensor = analogRead(smokeA0);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
   
    
     mySerial.println("OK"); 
     delay(1000);  // Delay of 1 second
     mySerial.println("ATD+917045097166;");
     delay(15000);
     mySerial.println("ATH");
     digitalWrite(buzzer, HIGH);
     delay(1000);
     mySerial.println("AT+CMGF=1");
     delay(1000);
     mySerial.println("AT+CMGS=\"+917045097166\"\r");
     delay(1000);
     mySerial.println("Gas Leakage Alert");
     delay(100);
     mySerial.println((char)26);
     delay(100);
      digitalWrite(redbulb, HIGH);
    digitalWrite(greenbulb, LOW);
     

  }
  else
  {
    digitalWrite(redbulb, LOW);
    digitalWrite(greenbulb, HIGH);
    digitalWrite(buzzer,HIGH);
  }
  delay(50);
}
