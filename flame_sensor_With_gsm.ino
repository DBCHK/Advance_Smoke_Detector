const int buzzerPin = 12;
const int flamePin = 11;
int Flame = HIGH;
int redled = 5;
int greenled = 6;
void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);

  pinMode(flamePin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  Flame = digitalRead(flamePin);
  if (Flame== LOW)
  {
    
      Serial.println("ATDxxxxxxxxx;"); // ATDxxxxxxxxxx; semicolon should be at the last ;AT command that follows UART protocol;
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(redled, HIGH);
    digitalWrite(greenled, LOW);
       Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     Serial.println("AT+CMGS=\"+917028264965\"\r"); // Replace x with mobile number
     Serial.println("Smoke Has Been Detected");// The SMS text you want to send
     Serial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
     //delay(100);
     
    
  }
  else
  {

    digitalWrite(buzzerPin, LOW);
    digitalWrite(greenled, HIGH);
    digitalWrite(redled, LOW);
  }
}
