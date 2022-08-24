
int sensorValue;  
int limit = 300; //Limit of moisture level

void setup() {
 Serial.begin(9600);//Initializing serial monitor with 9600 baud rate
 pinMode(D4, OUTPUT);//Pin controlling motor pump
 pinMode(A0, INPUT);//taking input from anlaog pin

}
void loop() {

 sensorValue = analogRead(A0); //taking input
 Serial.println("Analog Value : ");//Printing on Serial monitor analog value of moisture
 Serial.println(sensorValue);
 
 if (sensorValue>limit) {//if moisture anolog value greater than limit so low moisture 
     digitalWrite(D4, 0); //Starting the motor for 5 secs
     Serial.println("Low Moisture:- Giving Water for 5 seconds waiting 20 secs");//printing what is done
     delay(5000);
     digitalWrite(D4, 1); //Stoping motor 
     delay(20000);//waiting for 20secs
    
 
 }
 else {
    digitalWrite(D4, 1); //Stoping Motor
    Serial.println("Enough Moisture:- No Need of Water checking after 10 secs");
    delay(10000);
 }
  
}
