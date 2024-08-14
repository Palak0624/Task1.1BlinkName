#include "thingProperties.h"

// Define the LED pin

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  
  pinMode(LED_BUILTIN,OUTPUT);
  
}

const int dotDuration = 200;
const int dashDuration = dotDuration * 3;
const int interDotDashDuration = dotDuration;
const int letterGapDuration = dotDuration * 3;


int BUTTON_PIN = 3;

void dash() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(dashDuration);
  digitalWrite(LED_BUILTIN, LOW);
  delay(interDotDashDuration);
}

void dot() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(dotDuration);
  digitalWrite(LED_BUILTIN, LOW);
  delay(interDotDashDuration);
}

void print(){
  // TO PRINT .--. .- .-.. .- -.-
  dot();
  dash();
  dash();
  dot();

  delay(1000);
  //A
  dot();
  dash();

  delay(1000);
  //L
  dot();
  dash();
  dot();
  dot();

  delay(1000);
  
  //A
  dot();
  dash();

  delay(1000);
  
  //K
  dash();
  dot();
  dash();
  
}


void loop() {
  ArduinoCloud.update();
  // Your code here 
  while (led == HIGH || digitalRead(BUTTON_PIN) == HIGH){
    print();
  }
  
}


/*
  Since Led is READ_WRITE variable, onLedChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLedChange()  
{
  // Add your code here to act upon Led change
}



