//TMP36 Pin Variables
int sensorPin = 0; //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade with a
                        //500 mV offset to allow for negative temperatures
int fanPin = 1; //Pin used to control the fan
int heaterPin = 2; //Pin used to control the heater

void setup() //Serial connection for debuging and sat fan pin's output
{
  Serial.begin(9600);  //Start the serial connection with the computer
                       //to view the result open the serial monitor 
  pinMode(fanPin, OUTPUT);
  pinMode(heaterPin, OUTPUT);
}
 
void loop()                     // run over and over again
{
 Serial.println(getTemp());
 delay(1000);   //waiting a second
}

void fan_test(){
   //Spin the fan
  for(int x = 0; x <= 255; x+=5){
    analogWrite(fanPin, x);
    delay(50);
   }
  for(int x = 255; x >= 0; x-=5){
    analogWrite(fanPin, x);
    delay(50);
  }
}

float getTemp(){
  int reading = analogRead(sensorPin);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  //converting from 10 mv per degree wit 500 mV offset
  //to degrees ((voltage - 500mV) times 100);
  float tempC = (voltage - 0.5) * 100;
  return tempC;
}

