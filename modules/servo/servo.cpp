#include "mbed.h"
#include "arm_book_lib.h"

#include "servo.h"

PwmOut servo(PF_9); //Here is where we declare the object

void wiperHigh(){
    servo.write(DUTY_MIN); // 2.5% duty cycle
    delay(500);
    servo.write(DUTY_69);
    delay(1000);
}

void wiperLow(){
    servo.write(DUTY_MIN); // 2.5% duty cycle
    delay(500);
    servo.write(DUTY_69);
    delay(1500);

}
void wiperThree(){
    servo.write(DUTY_MIN); // 2.5% duty cycle
    delay(500);
    servo.write(DUTY_69);
    delay(2340);
}

void wiperSix(){
    servo.write(DUTY_MIN); // 2.5% duty cycle
    delay(500);
    servo.write(DUTY_69);
    delay(5340);
}

void wiperEight(){
    servo.write(DUTY_MIN); // 2.5% duty cycle
    delay(500);
    servo.write(DUTY_69);
    delay(7340);
}

void wiperOff(){
    servo.period(PERIOD); // 20ms period
    delay(300);
    servo.write(DUTY_MIN); // 2.5% duty cycle

}