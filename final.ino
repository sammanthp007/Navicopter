const int controlPin = 9;
int beforeStartWait = 100;
int startWait = beforeStartWait + 10000;
int afterStartWait = startWait + 5000;
int addTimeValue = 2000;
int minLiftOffValue = 130; // any value beyond this will fly
int maxLiftOffValue = 150;
int airTime = afterStartWait + 20000; // stays in air for this long
int airRetainValue = 130; // stays in air with this much motor rotation value
int reachDownValue = 110; // comes till this value to come down
int comeDownTime = airTime + 2000;
int waitTime1 = 110;
int waitTime2 = 120;

void setup()
{
  // put your setup code here, to run once:
  // initialize Serial
  Serial.begin(9600);
  
  // wait so that we can deffenrentiate between garbage values and programs values in Serial console, and start camera for beforeStartWait time
  while (millis() < beforeStartWait) {
  analogWrite(controlPin, 150);
  }
  
  Serial.print("\n\nProgram Starts\n");
}

void loop()
{
  Serial.print("\nLoop Starts\n");

  // Only stays on the ground for the first startWait time
  Serial.print("startWait time\n");
  while (millis() < startWait) {
    for(int fadeValue = minLiftOffValue ; fadeValue <= maxLiftOffValue; fadeValue +=4) {
      Serial.print("fadeValue = ");
      Serial.print(fadeValue);
      Serial.print("\n");
      analogWrite(controlPin, fadeValue);
      delay(20);
    }
  }
  
  Serial.print("\nstartWait time done\n");
  
  Serial.print("elevationTime\n");
  // Make elevation gain
  while (millis() < afterStartWait - 100) {
    for(int fadeValue = minLiftOffValue ; fadeValue <= maxLiftOffValue + 60; fadeValue +=4) { 
      // sets the value (range from 0 to 255):
      Serial.print("fadeValue = ");
      Serial.print(fadeValue);
      Serial.print("\n");
      analogWrite(controlPin, fadeValue);         
      // wait for 30 milliseconds to see the dimming effect    
      delay(5);                      
      }
  }
  Serial.print("\nelevationtime done\n");

   // Stay in air
   while (millis() < airTime) {
     for(int fadeValue = minLiftOffValue ; fadeValue <= maxLiftOffValue; fadeValue +=4) {
       Serial.print("fadeValue = ");
      Serial.print(fadeValue);
      Serial.print("\n");
      analogWrite(controlPin, fadeValue);
      delay(20);
     }
   }
   
   Serial.print("\nairtime done\n");
   // come down
   while (millis() < comeDownTime) {
     for (int fadeValue = airRetainValue; fadeValue >= reachDownValue; fadeValue -= 1) {
       analogWrite(controlPin, fadeValue);
       delay(90);
     }
   }

   Serial.print("\ndowntime done\n");

   
   //stay in ground

}

