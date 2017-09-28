int sensorPin = 2;
int value = 0;

void setup () {
  Serial.begin (9600);
}

void loop () {
  value = analogRead (sensorPin); //More light means a lower value and viceversa
  Serial.println (1023-value, DEC);
  //Serial.println (1023-value, DEC); //If you want the opposite behaviour-More light an upper value- use this line
  delay (50);
}
