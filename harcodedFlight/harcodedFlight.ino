const int controlPin = 9;
int beforeStartWait = 5000;
int startWait = beforeStartWait + 10000;
int afterStartWait = startWait + 5000;
int addTimeValue = 2000;
int minLiftOffValue = 70; // any value beyond this will fly
int maxLiftOffValue = 150;
int airTime = afterWaitTime + 20000; // stays in air for this long
int airRetainValue = 70; // stays in air with this much motor rotation value
int reachDownValue = 40; // comes till this value to come down


void setup()
{
  // put your setup code here, to run once:
  // initialize Serial
  Serial.begin(9600);
  
  // wait so that we can deffenrentiate between garbage values and programs values in Serial console, and start camera for beforeStartWait time
  while (millis() < beforeStartWait) {
  analogWrite(controlPin, 0);
  }
  
  Serial.print("\n\nProgram Starts\n");
}

void loop()
{
  Serial.print("\nLoop Starts\n");

  // Only stays on the ground for the first startWait time
  while (millis() < startWait) {
    analogWrite(controlPin, minLiftOffValue);
  }
  
  // Make elevation gain
  while (millis() < (afterStartWait) {
    for(int fadeValue = minLiftOffValue ; fadeValue <= maxLiftOffValue; fadeValue +=1) { 
      // sets the value (range from 0 to 255):
      Serial.print("fadeValue = ");
      Serial.print(fadeValue);
      Serial.print("\n");
      analogWrite(controlPin, fadeValue);         
      // wait for 30 milliseconds to see the dimming effect    
      delay(70);                      
    }
   
   // Stay in air
   while (millis() < airTime) {
     analogWrite(controlPin, airRetainValue);
   }
   
   // come down
   while (millis() < comeDownTime) {
     for (int fadeValue = airRetainValue; fadeValue >= reachDownValue; fadeValue -= 1) {
       analogWrite(controlPin, fadeValue);
       delay(90);
   }
   
   //stay in ground
   while (true) {
     analogWrite(controlPin, minLiftOffValue);
   }
}

