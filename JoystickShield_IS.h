/**
   JoystickShield - Arduino Library for JoystickShield (http://hardwarefun.com/projects/joystick-shield)

 *
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

#ifndef JoystickShield_H
#define JoystickShield_H

#define CENTERTOLERANCE 5

// Compatibility for Arduino 1.0

#if ARDUINO >= 100
    #include <Arduino.h>
#else    
    #include <WProgram.h>
#endif

/**
 * Enum to hold the different states of the Joystick
 *
 */
enum JoystickStates {
    CENTER,  // 0
    UP,
    RIGHT_UP,
    RIGHT,
    RIGHT_DOWN,
    DOWN,
    LEFT_DOWN,
    LEFT,
    LEFT_UP   //8
};

/**
 * Enum to hold the button states
 *
 */
enum ButtonStates {
    NO_BUTTON,     //0
    JOYSTICK_BUTTON,
    A_BUTTON,
    B_BUTTON,
    G_BUTTON,
    F_BUTTON,    //5
	E_BUTTON,
	D_BUTTON
};

/**
 * Class to encapsulate JoystickShield
 */
class JoystickShield {

public:

    JoystickShield(); // constructor

    void setJoystickPins (byte pinX, byte pinY);
    void setButtonPins(byte pinSelect, byte pinUp, byte pinRight, byte pinDown, byte pinLeft, byte pinF, byte pinE);
    void setThreshold(int xLow, int xHigh, int yLow, int yHigh);

    void processEvents();
    void processCallbacks();
	
	void calibrateJoystick();

    // Joystick events
    bool isCenter();
    bool isUp();
    bool isRightUp();
    bool isRight();
    bool isRightDown();
    bool isDown();
    bool isLeftDown();
    bool isLeft();
    bool isLeftUp();
	bool isNotCenter();
	
	// Joystick coordinates
	int xAmplitude();
	int yAmplitude();

    // Button events
    bool isJoystickButton();
    bool isAButton();
    bool isBButton();
    bool isGButton();
    bool isDButton();
	bool isFButton();
	bool isEButton();

    // Joystick callbacks
    void onJSCenter(void (*centerCallback)(void));
    void onJSUp(void (*upCallback)(void));
    void onJSRightUp(void (*rightUpCallback)(void));
    void onJSRight(void (*rightCallback)(void));
    void onJSRightDown(void (*rightDownCallback)(void));
    void onJSDown(void (*downCallback)(void));
    void onJSLeftDown(void (*leftDownCallback)(void));
    void onJSLeft(void (*leftCallback)(void));
    void onJSLeftUp(void (*leftUpCallback)(void));
	void onJSnotCenter(void (*notCenterCallback)(void));

    // Button callbacks
    void onJoystickButton(void (*jsButtonCallback)(void));
    void onaButton(void (*aButtonCallback)(void));
    void onbButton(void (*bButtonCallback)(void));
    void ongButton(void (*gButtonCallback)(void));
    void ondButton(void (*dButtonCallback)(void));
	void onfButton(void (*fButtonCallback)(void));
	void oneButton(void (*eButtonCallback)(void));
	
private:

    // threshold values
    int x_threshold_low;
    int x_threshold_high;
    int y_threshold_low;
    int y_threshold_high;

    // joystick pins
    byte pin_analog_x;
    byte pin_analog_y;

    //button pins
    byte pin_but_E;
    byte pin_but_D;
    byte pin_joystick_button;
    byte pin_but_B;
    byte pin_but_A;
    byte pin_but_F;
    byte pin_but_G;
    byte pin_But_E;
   
	// joystick
	byte joystikStroke;
	int x_position;
	int y_position;

    //current states of Joystick
    JoystickStates currentStatus;

    //current button states
    ButtonStates currentButton;

    // Joystick callbacks
    void (*centerCallback)(void);
    void (*upCallback)(void);
    void (*rightUpCallback)(void);
    void (*rightCallback)(void);
    void (*rightDownCallback)(void);
    void (*downCallback)(void);
    void (*leftDownCallback)(void);
    void (*leftCallback)(void);
    void (*leftUpCallback)(void);
	void (*notCenterCallback)(void);

    // Button callbacks
    void (*jsButtonCallback)(void);
    void (*aButtonCallback)(void);
    void (*bButtonCallback)(void);
    void (*gButtonCallback)(void);
    void (*dButtonCallback)(void);
	void (*fButtonCallback)(void);
	void (*eButtonCallback)(void);
	

    // helper functions
    void clearButtonStates();
    void initializeCallbacks();
};

#endif
