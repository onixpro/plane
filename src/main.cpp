#include <Arduino.h>
#include <Servo.h>
#include "ESC.h"

#define pin_in_y 14
#define pin_in_x 15

#define pin_esc 5

#define SPEED_MIN (1000)                                  // Set the Minimum Speed in microseconds
#define SPEED_MAX (2000)                                  // Set the Minimum Speed in microseconds

ESC myESC(pin_esc, SPEED_MIN, SPEED_MAX, 500);     
int oESC; 
  int val_x;
  int val_y;
  int potValue; 
char str[100];


void setup() {
  // put your setup code here, to run once:
  pinMode(pin_in_x, INPUT);
  pinMode(pin_in_y, INPUT);

   myESC.arm();                                            // Send the Arm value so the ESC will be ready to take commands
  //delay(5000);   

   //ESC.attach(pin_esc,1000,3000); // (pin, min pulse width, max pulse width in microseconds) 
   /*
   delay(2000);
   ESC.write(0);


   delay(2000);
   ESC.write(180);
*/
/*
    Serial.begin(9600);

    bool b_attached = ESC.attached();
Serial.println(b_attached); 

*/
Serial.begin(9600);
myESC.calib( );
Serial.println("test"); 
}

void loop() {



  val_x = analogRead(pin_in_x);
  val_y = analogRead(pin_in_y);


/*
    Serial.println(str); 
    if (val_x > 524) { 
  potValue = map(val_x, 524, 1023, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)
    }else{potValue = 0; }

  ESC.write(potValue);    // Send the signal to the ESC
  int esc_ms = ESC.readMicroseconds();
  sprintf(str,"X: %i, potValue: %i,esc_ms:%i", val_x,potValue,esc_ms);

  */
/*
   for (oESC = SPEED_MIN; oESC <= SPEED_MAX; oESC += 1) {  // goes from 1000 microseconds to 2000 microseconds
    myESC.speed(oESC);                                    // tell ESC to go to the oESC speed value
    delay(10);                                            // waits 10ms for the ESC to reach speed
  }
  delay(1000); */
  for (oESC = SPEED_MAX; oESC >= SPEED_MIN; oESC -= 100) {  // goes from 2000 microseconds to 1000 microseconds
    myESC.speed(oESC);                                    // tell ESC to go to the oESC speed value
    delay(10);                                            // waits 10ms for the ESC to reach speed  
   }
//  delay(5000); 
}