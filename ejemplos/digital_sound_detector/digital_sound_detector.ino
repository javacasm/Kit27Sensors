#define ANALOG_VALUE A0
int Led = 13 ;// define LED Interface
int buttonpin = 3; // define D0 Sensor Interface; 
int val ;// define numeric variables val

void setup ()
{
pinMode (Led, OUTPUT) ;// define LED as output interface
pinMode (buttonpin, INPUT) ;// output interface D0 is defined sensor
Serial.begin(9600);
}

void loop ()
{
  val = digitalRead (buttonpin) ;// digital interface will be assigned a value of 3 to read val
  if (val == HIGH) // When the sound detection module detects a signal, LED flashes
  {
    digitalWrite (Led, HIGH);
  }
  else
  {
    digitalWrite (Led, LOW);
  }
  Serial.println(analogRead(ANALOG_VALUE));
  delay(25);
}
