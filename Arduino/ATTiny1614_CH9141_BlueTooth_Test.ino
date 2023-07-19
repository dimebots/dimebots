void setup() {
Serial.swap(1);
Serial.begin(9600);
pinMode(2, OUTPUT);
 }

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0)
   {     
      char data= Serial.read(); // reading the data received from the bluetooth module
      switch(data)
      {
        case '1': digitalWrite(2, HIGH);break; 
        case '2': digitalWrite(2, LOW);break;         
        case '3': digitalWrite(2, HIGH);break;
        case '4': digitalWrite(2, LOW);break; 
       
        default : break;
      }
      Serial.println(data);
   }
   delay(50);
}
