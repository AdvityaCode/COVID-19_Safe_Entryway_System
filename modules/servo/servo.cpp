#include "mbed.h"
#include "arm_book_lib.h"

#include "servo.h"

#define SANITIZER_DELAY     1500

static void sanitizerClose();

PwmOut servo(PF_9); //Here is where we declare the object
PwmOut servo2(PF_7);
PwmOut gateServo(PF_8);

UnbufferedSerial servoDebug(USBTX, USBRX, 115200);

int servoDelay = 0;
Ticker servoTicker;

// Initializes the periods and starting positions for the servo motors
void servoInit(){
    servo.period(PERIOD); // 20ms period
    gateServo.period(PERIOD);
    servo2.period(PERIOD);

    servo.write(DUTY_MIN); // 2.5% duty cycle
    servo2.write(DUTY_MIN);
    gateServo.write(DUTY_MIN);

    servoTicker.attach(&sanitizerClose, 0.01);
}

// Dispenses the hand sanitizer
void sanitizerServoDispense() {
    servoDelay = 0;
    servo2.write(DUTY_69);  // Move to 67 degrees
    servo.write(DUTY_69);
}

// Open the entry gate
void gateServoOpen() {
    gateServo.write(DUTY_MIN);  // Move to 67 degrees
    servoDebug.write("Gate Open\n", 10);
}

// Close the entry gate
void gateServoClose() {
    gateServo.write(DUTY_69);  // Close Gate
    servoDebug.write("Gate Closed\n", 12);
}

// Resets the hand sanitizer after a delay of SANITIZER_DELAY
static void sanitizerClose() {
    servoDelay += 10;
    if (servoDelay >= SANITIZER_DELAY) {
        servo2.write(DUTY_MIN); // Move back to 0 degrees
        servo.write(DUTY_MIN);
    }
}