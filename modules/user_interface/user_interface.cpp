#include "mbed.h"
#include "arm_book_lib.h"

#include "user_interface.h"
#include "display.h"

// Initializes the diplay and writes the welcome message
void userInterfaceInit() {
    displayInit();
    displayWelcome();
}

// Writes the welcome message to the LCD display
void displayWelcome()
{
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "WELCOME TO GYM  " );
    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "SANITIZE PLEASE" );
}

// Writes the sanitization prompt to the LCD display
void displaySantized()
{
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "SANITIZED?      " );
    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "USE GAS SENSOR  " );

}

// Writes the temperature check prompt to the LCD display
void displayCheckTemp()
{
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "GOOD  JOB       " );

    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "GET TEMP CHECKED" );
}

// Writes the entry granted message to the LCD display
void entryGranted()
{
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "YOU ARE HEALTHY " );

    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "ENTER ALUMNI GYM" );
}

// Writes the entry denied message to the LCD display
void entryDeniedTemp()
{
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "TEMP  TOO  HIGH " );

    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "ENTRY DENIED    " );
}

// POSSIBLE DELETE
void entryDeniedUnsantized()
{
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "UNSANTIZED      " );

    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "ENTRY DENIED    " );
}
