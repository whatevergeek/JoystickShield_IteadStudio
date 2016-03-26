/**
   JoystickShield - Arduino Library for JoystickShield (http://hardwarefun.com/projects/joystick-shield)

   Copyright 2011  Sudar Muthu  (email : sudar@sudarmuthu.com)

 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <sudar@sudarmuthu.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer or coffee in return - Sudar
 * ----------------------------------------------------------------------------
 * 2014 edit by Markus Mücke, muecke.ma(a)gmail.com
 * Changes for JoysikShield V1.2
 * added a function to read the amplitude of the joystick
 * added a auto calibrate function for 3.3V and 5V mode
 *
 * Added functions:
 *  Functions for F and E Button
 *  Calibrate Joystick
 *  xAmplitude
 *  yAmplitude
 *
 * 26March2016 edited by Paul Amazona, irondata@outlook.com
 * Source code for Arduino Joystick Shield from Itead Studio
 * Edited to work explicitly for JoystickShield: http://wiki.iteadstudio.com/ITEAD_Joystick_shield
 * Renamed a number of variables/methods to avoid confusion.
 */

/**
 * Before running this example, stack the JoystickShield on top of Arduino board
 *
 */
#include <JoystickShield_IS.h> // include JoystickShield Library

JoystickShield joystickShield; // create an instance of JoystickShield object

void setup() {
    Serial.begin(9600);
    
    delay(100);
    // new calibration function
    joystickShield.calibrateJoystick();    
    
    // Joystick Callbacks
    joystickShield.onJSUp(&up);
    joystickShield.onJSRightUp(&rightUp);
    joystickShield.onJSRight(&right);
    joystickShield.onJSRightDown(&rightDown);
    joystickShield.onJSDown(&down);
    joystickShield.onJSLeftDown(&leftDown);
    joystickShield.onJSLeft(&left);
    joystickShield.onJSLeftUp(&leftUp);
    joystickShield.onJSnotCenter(&notCenter);

    // Button Callbacks
    joystickShield.onJoystickButton(&joystickButton);
    joystickShield.onaButton(&AButton);
    joystickShield.onbButton(&BButton);
    joystickShield.ongButton(&GButton);
    joystickShield.onfButton(&FButton);
    joystickShield.oneButton(&EButton);
    joystickShield.ondButton(&DButton);
}


void loop() {
    joystickShield.processCallbacks(); // you don't have do anything else
    delay(500);
}

/** Define Callback Function **/
void up() {
    Serial.println("Up from callback");
}

void rightUp() {
    Serial.println("Right Up from callback");
}

void right() {
    Serial.println("Right from callback");
}

void rightDown() {
    Serial.println("Right Down from callback");
}

void down() {
    Serial.println("Down from callback");
}

void leftDown() {
    Serial.println("Left Down from callback");
}

void left() {
    Serial.println("Left from callback");
}

void leftUp() {
    Serial.println("Left Up from callback");
}

void joystickButton() {
    Serial.println("Joystick from callback");
}

void AButton() {
    Serial.println("A Button from callback");
}

void BButton() {
    Serial.println("B Button from callback");
}

void GButton() {
    Serial.println("G Button from callback");
}

void FButton() {
    Serial.println("F Button from callback");
}

void EButton() {
    Serial.println("E Button from callback");
}

void DButton() {
    Serial.println("D Button from callback");
}

void notCenter() {
   Serial.println("Not Center from callback");
   // new position functions
   Serial.print("x ");	Serial.print(joystickShield.xAmplitude());Serial.print(" y ");Serial.println(joystickShield.yAmplitude());
}
