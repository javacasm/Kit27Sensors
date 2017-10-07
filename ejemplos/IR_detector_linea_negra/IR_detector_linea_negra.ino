int Led = 13 ;// define LED Interface
int buttonpin = 3; // define Tracking Sensor Interface
int val ;// define numeric variables val

void setup ()
{
pinMode (Led, OUTPUT) ;// define LED as output interface
pinMode (buttonpin, INPUT) ;// define Tracking sensor output interface
}

void loop ()
{
  val = digitalRead (buttonpin) ;// digital interface will be assigned a value of 3 to read valhttp://keyes-arduino.taobao.com
  if (val == HIGH) // When the Tracking sensor detects a signal, LED flashes
  {
    digitalWrite (Led, HIGH);
  }
  else
  {
    digitalWrite (Led, LOW);
  }
}
