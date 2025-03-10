#include "MLX90614.h"
#include "mbed.h"
#include "arm_book_lib.h"
#include "temp_sensor.h"

#define TEMP_ARRAY_LENGTH       10

MLX90614 myMLX90614   ( D14, D15, 0x5A << 1, 100000 );

Ticker newReading;
//DigitalOut myled(LED3);

MLX90614::MLX90614_status_t         aux;
MLX90614::MLX90614_vector_data_t    myMLX90614Data;
uint8_t                             readTemp = 0;

float tempArray[TEMP_ARRAY_LENGTH];

char str[100];
int stringLength;

char IDstring[100];
int IDlength;

//aux  =   myMLX90614.MLX90614_GetID_Numbers ( &myMLX90614Data );

//static float getTempF();
static void changeDATA();

// Takes a new reading of the temperature if readTemp == 1;
void temp_sensor_update() { 


    //int tempIndex = 0;

    //myled = 1;

    if ( readTemp == 1 ) {

        aux  =   myMLX90614.MLX90614_ReadTObj1     ( &myMLX90614Data );
        
        /*tempArray[tempIndex] = getTempF();

        if (tempIndex >= TEMP_ARRAY_LENGTH - 1) {
            tempIndex = 0;
        } else {
            tempIndex++;
        }*/
        
    }

    //myled = 0;
}

// Initializes the temp 
void temp_sensor_init() {
    newReading.attach( &changeDATA, 1 );
    aux  =   myMLX90614.MLX90614_GetID_Numbers ( &myMLX90614Data );
}

// Allows the temp to be resampled
static void changeDATA ( void )
{
    readTemp = 1;
}

// Returns the average temperature of the last 10 samples
float getTempAvg() {
    float tempTotal = 0;

    for (int i = 0; i < TEMP_ARRAY_LENGTH; i++) {
        tempTotal += tempArray[i];
    }

    return tempTotal/((float)TEMP_ARRAY_LENGTH);
}

// Returns the temperature of the object in Farenheit
float getTempF() {
    return (myMLX90614Data.TObj1 * (9.0/5.0)) + 32.0;
}
