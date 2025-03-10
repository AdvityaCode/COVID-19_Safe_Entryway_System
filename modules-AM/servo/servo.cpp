#include "mbed.h"
#include "arm_book_lib.h"

#include "servo.h"
#include "distance_sensor.h"

PwmOut servo(PF_9); //Here is where we declare the object
PwmOut servo2(PF_7);
PwmOut gateServo(PF_8);

void wiperHigh(){
    servo.write(DUTY_MIN); // 2.5% duty cycle
    delay(500);
    servo.write(DUTY_69);
    delay(1000);
}

void wiperInitialize(){
    servo.period(PERIOD); // 20ms period
    delay(300);
    servo.write(DUTY_MIN); // 2.5% duty cycle
}

void wiperSingleMove() {
    servo.write(DUTY_69);  // Move to 67 degrees
    delay(1500);      // ✅ Wait 1.5 seconds for full movement
    servo.write(DUTY_MIN); // Move back to 0 degrees
    delay(1500);      // ✅ Wait 1.5 seconds for full movement
}

void wiperSingleMove2() {
    servo2.write(DUTY_69);  // Move to 67 degrees
    servo.write(DUTY_69);
    delay(1500);      // ✅ Wait 1.5 seconds for full movement
    servo2.write(DUTY_MIN); // Move back to 0 degrees
    servo.write(DUTY_MIN);
    delay(1500);      // ✅ Wait 1.5 seconds for full movement
}

void gateServoOpen() {
    gateServo.write(DUTY_69);  // Move to 67 degrees
}

void gateServoClose() {
    gateServo.write(DUTY_MIN);  // Close Gate
}