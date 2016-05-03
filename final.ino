const int controlPin = 9;
int startWait = 20000;
int afterStartWait = startWait + 2000;
int addTimeValue = 2000;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (millis() < startWait) {
    int a = 0;
  }
  Serial.print("\n\nProgram Starts\n");
  Serial.print("After Start, turning the LED on, setting the max for controlPin \n");
  while (millis() < afterStartWait) {
   analogWrite(controlPin, 205); 
  }
  
  Serial.print("After Start, turning the LED off, setting the min value\n");
  while (millis() < afterStartWait + addTimeValue) {
//    digitalWrite(controlPin, HIGH);
    analogWrite(controlPin, 0);
  }
  
  Serial.print("\nLets start\n");
}

void loop()
{
  Serial.print("\nInitial Value\n");
  // put your main code here, to run repeatedly:
  for(int fadeValue = 110 ; fadeValue <= 205; fadeValue +=1) { 
    // sets the value (range from 0 to 255):
    Serial.print("fadeValue = ");
    Serial.print(fadeValue);
    Serial.print("\n");
    analogWrite(controlPin, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(20);                         
  } 
}

