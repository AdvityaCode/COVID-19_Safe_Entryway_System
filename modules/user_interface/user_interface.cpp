#include "mbed.h"
#include "arm_book_lib.h"

#include "user_interface.h"
#include "display.h"


void displayWelcome()
{
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "WELCOME TO ALUMNI GYM" );
}

void displayLow()
{
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Mode: LO" );

}

void displayOff()
{
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Mode: OFF" );

}

void displayInt3()
{
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Mode: INT SHORT" );
}

void displayInt6()
{
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Mode: INT MEDIUM" );
}

void displayInt8()
{
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Mode: INT LONG" );

}





