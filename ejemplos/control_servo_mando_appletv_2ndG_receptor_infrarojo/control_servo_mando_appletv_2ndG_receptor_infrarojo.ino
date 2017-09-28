#include <IRremote.h>
#include <Servo.h>

#define RECV_PIN 11 // define input pin on Arduino
#define servomotor 8  

IRrecv irrecv (RECV_PIN);
decode_results results;
Servo myservo;

int angle=0;
int angle_increment=5;

void setup ()
{
  Serial.begin (9600);
  irrecv.enableIRIn (); // Start the receiver
  myservo.attach(servomotor);
}

void loop () {
  if (irrecv.decode (& results)) {
    Serial.println (results.value, HEX);
    irrecv.resume (); // Receive the next value
  }
  if(results.value==0x77E1BAC3) //Central button
  {
    angle=90;
  }
  else if (results.value==0x77E17AC3) //Play button
  {
    angle=0;
  }
  else if (results.value==0x77E140C3) //Menu button
  {
    angle=180;
  }
  else if (results.value==0x77E1E0C3) //Right button
  {
    if(angle>0)
    {
      angle=angle-angle_increment;
    }
    results.value=0;
  }
  else if (results.value==0x77E110C3) //Left button
  {
    if(angle<180)
    {
      angle=angle+angle_increment;
    }
    results.value=0;
  }
  else if (results.value==0x77E1D0C3) //Up button
  {
    if(angle_increment<180)
    {
    angle_increment=angle_increment+5;
    }
    results.value=0;
  }
  else if (results.value==0x77E1B0C3) //Down button
  {
    if(angle_increment>5)
    {
    angle_increment=angle_increment-5;
    }
    results.value=0;
  }
  myservo.write(angle); 

}

/*

 Hexadecimal values of the buttons

  - Central button : 77E1BAC3
                     End of pulse 77E120C3


  - Play/pause button: 77E17AC3
                       End of pulse 77E120C3


  - Menu button    : 77E140C3

  - Right button   : 77E1E0C3

  - Left button    : 77E110C3

  - Up button      : 77E1D0C3

  - Down button    : 77E1B0C3
  
 */
