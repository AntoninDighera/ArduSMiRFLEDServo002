/******************************************
 *   ArduinoBluetoothWithSmirfLED3Servos  *
 ******************************************/

/** @author Dom Dighera
 *  @edited Xavier Prospero
 */

#include <SoftwareSerial.h>
#include <Servo.h>

/*****************************************
 *       Global Var Declarations         *
 *****************************************/

/** TX, RX vars. Respectively.*/
SoftwareSerial BT(10, 11);

/** Introduces the servos and names them. */
Servo servo1;
Servo servo2;
Servo servo3;

/* Corresponds to the state of the of the state
 * of the ____. */
String state;

/*****************************************
 *                  SETUP                *
 *****************************************/
/** Gets data for the serial monitor. Then
 *  writes to the different servos to control
 *  them. */
void setup() {

  BT.begin(115200);
  Serial.begin(9600);

  pinMode(13, OUTPUT);

  servo1.attach(3);
  servo2.attach(6);
 //servo3.attach(3);    FIXME?

  servo1.write(90);
  servo2.write(90);
 //servo3.write(90);   FIXME


}


/*****************************************
 *                  LOOP                 *
 *****************************************/
/** Opening loop checks if there is an input then
  * sets c. Has a delay to keep reads stable. Then
  * iterates over different servos and writes to
  * them. */
void loop() {
  while (BT.available())  {
    delay(10);
    char c = BT.read();
    state.concat(c);
  }

  if (state.length() > 0) {
    Serial.println(state);
    if(state.equals("On")) {
      digitalWrite(13, HIGH);           //Turn LED (13~) on
    } else {
      digitalWrite(13, LOW);          //Turn LED (13~) off
    }
    if (state.equals("S1")) {
      servo1.write(120);              //Make Servo 1 move
      delay(2000);
      servo1.write(50);
      delay(1000);
      servo1.write(90);
    }
    if (state.equals("S2")) {                //Make Servo 2 move
      servo2.write(120);
      delay(2000);
      servo2.write(50);
      delay(1000);
      servo2.write(90);
    }
    if (state.equals("S3")) {                 //Make Servo 3 move
      servo3.write(120);
      delay(2000);
      servo3.write(50);
      delay(1000);
      servo3.write(90);
    }


state.remove(0);                      //after loop finished change the value of the 'state' variable to blank and LOOP

}

} //Reset the variable
