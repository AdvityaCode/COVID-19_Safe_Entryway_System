#include "mbed.h"
#include "arm_book_lib.h"

#include "user_interface.h"
#include "display.h"


void displayWelcome()
{
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "WELCOME TO GYM  " );
    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "SANITIZE PLEASE" );
}

void displaySantized()
{
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "SANITIZED?      " );
    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "USE GAS SENSOR  " );

}

void displayCheckTemp()
{
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "GOOD  JOB       " );

    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "GET TEMP CHECKED" );
}

void entryGranted()
{
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "YOU ARE HEALTHY " );

    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "ENTER ALUMNI GYM" );
}

void entryDeniedTemp()
{
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "TEMP  TOO  HIGH " );

    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "ENTRY DENIED    " );
}

void entryDeniedUnsantized()
{
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "UNSANTIZED      " );

    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "ENTRY DENIED    " );
}
