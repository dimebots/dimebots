
  int pinled = 2;

  void setup() {                
    // initialize the digital pin as an output.
    pinMode(pinled, OUTPUT);     
  }

  // the loop routine runs over and over again forever:
  void loop() {
    digitalWrite(pinled, HIGH);   // turn the LED on 
    delay(100);               // wait for a second
    digitalWrite(pinled, LOW);    // turn the LED off 
    delay(100);               // wait for a second
  }

