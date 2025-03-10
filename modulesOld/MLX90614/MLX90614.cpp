/**
 * @brief       MLX90614.cpp
 * @details     Single and Dual Zone Infra Red Thermometer.
 *              Function file.
 *
 *
 * @return      NA
 *
 * @author      Manuel Caballero
 * @date        26/December/2017
 * @version     26/December/2017    The ORIGIN
 * @pre         NaN.
 * @warning     NaN
 * @pre         This code belongs to AqueronteBlog ( http://unbarquero.blogspot.com ).
 */

#include "MLX90614.h"
#include "mbed.h"


MLX90614::MLX90614 ( PinName sda, PinName scl, uint32_t addr, uint32_t freq )
    : _i2c          ( sda, scl )
    , _MLX90614_Addr  ( addr )
{
    _i2c.frequency( freq );
}


MLX90614::~MLX90614()
{
}




/**
 * @brief       MLX90614_GetID_Numbers ( MLX90614_vector_data_t* )
 *
 * @details     It gets the ID numbers.
 *
 * @param[in]    NaN
 *
 * @param[out]   myID:              ID numbers.
 *
 *
 * @return       Status of MLX90614_GetID_Numbers.
 *
 *
 * @author      Manuel Caballero
 * @date        26/December/2017
 * @version     26/December/2017     The ORIGIN
 * @pre         NaN.
 * @warning     NaN.
 */
MLX90614::MLX90614_status_t  MLX90614::MLX90614_GetID_Numbers ( MLX90614_vector_data_t*  myID )
{
    char         cmd[]       =   { 0, 0, 0 };
    uint32_t     aux         =   0;


    // It gets the ID 0
    cmd[0]   =   MLX90614_ID_NUMBER_0;
    aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
    aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );

    myID->ID[0]  =   ( ( cmd[1] << 8 ) | cmd[0] );


    // It gets the ID 1
    cmd[0]   =   MLX90614_ID_NUMBER_1;
    aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
    aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );

    myID->ID[1]  =   ( ( cmd[1] << 8 ) | cmd[0] );


    // It gets the ID 2
    cmd[0]   =   MLX90614_ID_NUMBER_2;
    aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
    aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );

    myID->ID[2]  =   ( ( cmd[1] << 8 ) | cmd[0] );


    // It gets the ID 3
    cmd[0]   =   MLX90614_ID_NUMBER_3;
    aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
    aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );

    myID->ID[3]  =   ( ( cmd[1] << 8 ) | cmd[0] );




    if ( aux == I2C_SUCCESS )
        return   MLX90614_SUCCESS;
    else
        return   MLX90614_FAILURE;
}


/**
 * @brief       MLX90614_ReadRawTA ( MLX90614_vector_data_t* )
 *
 * @details     It raw ambient temperature.
 *
 * @param[in]    NaN.
 *
 * @param[out]   myRawTA:           Raw ambient temperature.
 *
 *
 * @return       Status of MLX90614_ReadRawTA.
 *
 *
 * @author      Manuel Caballero
 * @date        26/December/2017
 * @version     26/December/2017     The ORIGIN
 * @pre         NaN.
 * @warning     NaN.
 */
MLX90614::MLX90614_status_t  MLX90614::MLX90614_ReadRawTA ( MLX90614_vector_data_t*  myRawTA )
{
    char         cmd[]       =   { MLX90614_TA, 0, 0 };
    uint32_t     aux         =   0;


    // It gets the raw ambient temperature
    aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
    aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );


    myRawTA->RawTA  =   ( ( cmd[1] << 8 ) | cmd[0] );
    myRawTA->PEC    =   cmd[2];

    // Check if flag error is triggered ( faulty if so )
    if ( ( myRawTA->RawTA & MLX90614_FLAG_ERROR ) == MLX90614_FLAG_ERROR )
        return   MLX90614_FAILURE;


    if ( aux == I2C_SUCCESS )
        return   MLX90614_SUCCESS;
    else
        return   MLX90614_FAILURE;
}


/**
 * @brief       MLX90614_ReadTA ( MLX90614_vector_data_t* )
 *
 * @details     It ambient temperature.
 *
 * @param[in]    NaN
 *
 * @param[out]   myTA:              Ambient temperature in Celsius.
 *
 *
 * @return       Status of MLX90614_ReadTA.
 *
 *
 * @author      Manuel Caballero
 * @date        26/December/2017
 * @version     26/December/2017     The ORIGIN
 * @pre         NaN.
 * @warning     NaN.
 */
MLX90614::MLX90614_status_t  MLX90614::MLX90614_ReadTA ( MLX90614_vector_data_t*  myTA )
{
    char         cmd[]       =   { MLX90614_TA, 0, 0 };
    uint32_t     aux         =   0;


    // It gets the raw ambient temperature
    aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
    aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );


    myTA->TA  =   ( MLX90614_KELVIN_CONVERSION * ( ( ( cmd[1] << 8 ) | cmd[0] ) ) ) - MLX90614_KELVIN_TO_CELSIUS;
    myTA->PEC =   cmd[2];

    // Check if flag error is triggered ( faulty if so )
    if ( ( cmd[1] & ( MLX90614_FLAG_ERROR >> 8 ) ) == ( MLX90614_FLAG_ERROR >> 8 ) )
        return   MLX90614_FAILURE;


    if ( aux == I2C_SUCCESS )
        return   MLX90614_SUCCESS;
    else
        return   MLX90614_FAILURE;
}


/**
 * @brief       MLX90614_ReadRawTObj1 ( MLX90614_vector_data_t* )
 *
 * @details     It raw object 1 temperature.
 *
 * @param[in]    NaN.
 *
 * @param[out]   myRawTObj1:        Raw object 1 temperature.
 *
 *
 * @return       Status of MLX90614_ReadRawTObj1.
 *
 *
 * @author      Manuel Caballero
 * @date        26/December/2017
 * @version     26/December/2017     The ORIGIN
 * @pre         NaN.
 * @warning     NaN.
 */
MLX90614::MLX90614_status_t  MLX90614::MLX90614_ReadRawTObj1 ( MLX90614_vector_data_t*  myRawTObj1 )
{
    char         cmd[]       =   { MLX90614_TOBJ_1, 0, 0 };
    uint32_t     aux         =   0;


    // It gets the raw object 1 temperature
    aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
    aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );


    myRawTObj1->RawTObj1  =   ( ( cmd[1] << 8 ) | cmd[0] );
    myRawTObj1->PEC       =   cmd[2];

    // Check if flag error is triggered ( faulty if so )
    if ( ( myRawTObj1->RawTObj1 & MLX90614_FLAG_ERROR ) == MLX90614_FLAG_ERROR )
        return   MLX90614_FAILURE;


    if ( aux == I2C_SUCCESS )
        return   MLX90614_SUCCESS;
    else
        return   MLX90614_FAILURE;
}


/**
 * @brief       MLX90614_ReadTObj1 ( MLX90614_vector_data_t* )
 *
 * @details     It object 1 temperature.
 *
 * @param[in]    NaN.
 *
 * @param[out]   myTObj1:           Object 1 temperature in Celsius.
 *
 *
 * @return       Status of MLX90614_ReadTObj1.
 *
 *
 * @author      Manuel Caballero
 * @date        26/December/2017
 * @version     26/December/2017     The ORIGIN
 * @pre         NaN.
 * @warning     NaN.
 */
MLX90614::MLX90614_status_t  MLX90614::MLX90614_ReadTObj1 ( MLX90614_vector_data_t*  myTObj1 )
{
    char         cmd[]       =   { MLX90614_TOBJ_1, 0, 0 };
    uint32_t     aux         =   0;


    // It gets the raw object 1 temperature
    aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
    aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );


    myTObj1->TObj1  =   ( MLX90614_KELVIN_CONVERSION * ( ( ( cmd[1] << 8 ) | cmd[0] ) ) ) - MLX90614_KELVIN_TO_CELSIUS;
    myTObj1->PEC    =   cmd[2];

    // Check if flag error is triggered ( faulty if so )
    if ( ( cmd[1] & ( MLX90614_FLAG_ERROR >> 8 ) ) == ( MLX90614_FLAG_ERROR >> 8 ) )
        return   MLX90614_FAILURE;


    if ( aux == I2C_SUCCESS )
        return   MLX90614_SUCCESS;
    else
        return   MLX90614_FAILURE;
}


/**
 * @brief       MLX90614_ReadRawTObj2 ( MLX90614_vector_data_t* )
 *
 * @details     It raw object 2 temperature.
 *
 * @param[in]    NaN.
 *
 * @param[out]   myRawTObj1:        Raw object 2 temperature.
 *
 *
 * @return       Status of MLX90614_ReadRawTObj2.
 *
 *
 * @author      Manuel Caballero
 * @date        26/December/2017
 * @version     26/December/2017     The ORIGIN
 * @pre         NaN.
 * @warning     NaN.
 */
MLX90614::MLX90614_status_t  MLX90614::MLX90614_ReadRawTObj2 ( MLX90614_vector_data_t*  myRawTObj2 )
{
    char         cmd[]       =   { MLX90614_TOBJ_2, 0, 0 };
    uint32_t     aux         =   0;


    // It gets the raw object 1 temperature
    aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
    aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );


    myRawTObj2->RawTObj2  =   ( ( cmd[1] << 8 ) | cmd[0] );
    myRawTObj2->PEC       =   cmd[2];

    // Check if flag error is triggered ( faulty if so )
    if ( ( myRawTObj2->RawTObj2 & MLX90614_FLAG_ERROR ) == MLX90614_FLAG_ERROR )
        return   MLX90614_FAILURE;


    if ( aux == I2C_SUCCESS )
        return   MLX90614_SUCCESS;
    else
        return   MLX90614_FAILURE;
}


/**
 * @brief       MLX90614_ReadTObj2 ( MLX90614_vector_data_t* )
 *
 * @details     It object 2 temperature.
 *
 * @param[in]    NaN.
 *
 * @param[out]   myTObj2:           Object 2 temperature in Celsius.
 *
 *
 * @return       Status of MLX90614_ReadTObj2.
 *
 *
 * @author      Manuel Caballero
 * @date        26/December/2017
 * @version     26/December/2017     The ORIGIN
 * @pre         NaN.
 * @warning     NaN.
 */
MLX90614::MLX90614_status_t  MLX90614::MLX90614_ReadTObj2 ( MLX90614_vector_data_t*  myTObj2 )
{
    char         cmd[]       =   { MLX90614_TOBJ_2, 0, 0 };
    uint32_t     aux         =   0;


    // It gets the raw object 2 temperature
    aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
    aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );


    myTObj2->TObj2  =   ( MLX90614_KELVIN_CONVERSION * ( ( ( cmd[1] << 8 ) | cmd[0] ) ) ) - MLX90614_KELVIN_TO_CELSIUS;
    myTObj2->PEC    =   cmd[2];

    // Check if flag error is triggered ( faulty if so )
    if ( ( cmd[1] & ( MLX90614_FLAG_ERROR >> 8 ) ) == ( MLX90614_FLAG_ERROR >> 8 ) )
        return   MLX90614_FAILURE;


    if ( aux == I2C_SUCCESS )
        return   MLX90614_SUCCESS;
    else
        return   MLX90614_FAILURE;
}


/**
 * @brief       MLX90614_GetEmissivity ( MLX90614_vector_data_t* )
 *
 * @details     It gets the Emissivity correction coefficient.
 *
 * @param[in]    NaN
 *
 * @param[out]   myEmissivity:      Emissivity correction coefficient.
 *
 *
 * @return       Status of MLX90614_GetEmissivity.
 *
 *
 * @author      Manuel Caballero
 * @date        26/December/2017
 * @version     26/December/2017     The ORIGIN
 * @pre         NaN.
 * @warning     NaN.
 */
MLX90614::MLX90614_status_t  MLX90614::MLX90614_GetEmissivity ( MLX90614_vector_data_t* myEmissivity )
{
    char         cmd[]       =   { MLX90614_EMISSIVITY_CORRECTION_COEFFICIENT, 0, 0 };
    uint32_t     aux         =   0;


    // It gets the Emissivity correction coefficient
    aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
    aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );


    myEmissivity->Emissivity  =   ( ( cmd[1] << 8 ) | cmd[0] );
    myEmissivity->Emissivity /=   65535;
    myEmissivity->PEC         =   cmd[2];




    if ( aux == I2C_SUCCESS )
        return   MLX90614_SUCCESS;
    else
        return   MLX90614_FAILURE;
}


/**
 * @brief       MLX90614_SetEmissivity ( MLX90614_vector_data_t* )
 *
 * @details     It sets the Emissivity correction coefficient.
 *
 * @param[in]    NaN.
 * @param[in]    myEmissivity:      Emissivity correction coefficient.
 *
 * @param[out]   NaN
 *
 *
 * @return       Status of MLX90614_SetEmissivity.
 *
 *
 * @author      Manuel Caballero
 * @date        26/December/2017
 * @version     26/December/2017     The ORIGIN
 * @pre         NaN.
 * @warning     NaN.
 */
MLX90614::MLX90614_status_t  MLX90614::MLX90614_SetEmissivity ( MLX90614_vector_data_t myEmissivity )
{
    char         cmd[]       =   { MLX90614_EMISSIVITY_CORRECTION_COEFFICIENT, 0, 0 };
    uint32_t     aux         =   0;
    uint32_t     ii          =   0;


    // Check Emissivity range
    if ( ( myEmissivity.Emissivity >= 0.1 ) && ( myEmissivity.Emissivity <= 1) )
    {
        // Erase EEPROM
        cmd[1]   =   0;
        aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 2, false );

        // It takes EEPROM about 5ms to write/read
        do
        {
            cmd[0]   =   MLX90614_FLAGS;
            aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
            aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], 3 );
            ii++;                                                                                 // Increase the timeout
        }
        while ( ( ( cmd[0] & FLAG_EEBUSY_HIGH ) == FLAG_EEBUSY_HIGH ) && ( ii < MLX90614_TIMEOUT ) );


        // If TIMEOUT, exit with failure.
        if ( ii >= MLX90614_TIMEOUT )
            return MLX90614_FAILURE;
        else
        {
            // Update the new value
            cmd[0]   =   MLX90614_EMISSIVITY_CORRECTION_COEFFICIENT;
            cmd[1]   =   _MYROUND( 65535 * myEmissivity.Emissivity );
            aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 2, false );
        }
    }
    else
        return MLX90614_FAILURE;




    if ( aux == I2C_SUCCESS )
        return   MLX90614_SUCCESS;
    else
        return   MLX90614_FAILURE;
}


/**
 * @brief       MLX90614_GetIIR ( MLX90614_vector_data_t* )
 *
 * @details     It gets the IIR.
 *
 * @param[in]    NaN.
 *
 * @param[out]   myIIR:             IIR.
 *
 *
 * @return       Status of MLX90614_GetIIR.
 *
 *
 * @author      Manuel Caballero
 * @date        26/December/2017
 * @version     26/December/2017     The ORIGIN
 * @pre         NaN.
 * @warning     NaN.
 */
MLX90614::MLX90614_status_t  MLX90614::MLX90614_GetIIR ( MLX90614_vector_data_t* myIIR )
{
    char         cmd[]       =   { MLX90614_CONFIG_REGISTER_1, 0, 0 };
    uint32_t     aux         =   0;


    // It gets the IIR
    aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
    aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );


    myIIR->IIR   =   ( MLX90614_configregister1_iir_t )( cmd[0] & CONFIGREG1_IIR_MASK );
    myIIR->PEC   =   cmd[2];




    if ( aux == I2C_SUCCESS )
        return   MLX90614_SUCCESS;
    else
        return   MLX90614_FAILURE;
}


/**
 * @brief       MLX90614_SetIIR ( MLX90614_configregister1_iir_t )
 *
 * @details     It sets the IIR.
 *
 * @param[in]    NaN.
 * @param[in]    myIIR:             IIR.
 *
 * @param[out]   NaN.
 *
 *
 * @return       Status of MLX90614_SetIIR.
 *
 *
 * @author      Manuel Caballero
 * @date        26/December/2017
 * @version     26/December/2017     The ORIGIN
 * @pre         NaN.
 * @warning     NaN.
 */
MLX90614::MLX90614_status_t  MLX90614::MLX90614_SetIIR ( MLX90614_configregister1_iir_t myIIR )
{
    char         cmd[]       =   { MLX90614_CONFIG_REGISTER_1, 0, 0 };
    uint32_t     aux         =   0;
    uint32_t     ii          =   0;


    // It gets the IIR
    aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
    aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );

    // Erase EEPROM
    cmd[2]   =   cmd[1];                                                       // MSB
    cmd[1]   =   ( cmd[0] & ~CONFIGREG1_IIR_MASK );                            // LSB
    cmd[0]   =   MLX90614_CONFIG_REGISTER_1;                                   // Command
    aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 3, false );

    // It takes EEPROM about 5ms to write/read
    do
    {
        cmd[0]   =   MLX90614_FLAGS;
        aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
        aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], 3 );
        ii++;                                                                                 // Increase the timeout
    }
    while ( ( ( cmd[0] & FLAG_EEBUSY_HIGH ) == FLAG_EEBUSY_HIGH ) && ( ii < MLX90614_TIMEOUT ) );


    // If TIMEOUT, exit with failure.
    if ( ii >= MLX90614_TIMEOUT )
        return MLX90614_FAILURE;
    else
    {
        // It gets the IIR
        aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
        aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );

        // Update the new value
        cmd[2]   =   cmd[1];                                                       // MSB
        cmd[1]   =   ( ( cmd[0] & ~CONFIGREG1_IIR_MASK ) | myIIR );                // LSB
        cmd[0]   =   MLX90614_CONFIG_REGISTER_1;                                   // Command
        aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 2, false );
    }




    if ( aux == I2C_SUCCESS )
        return   MLX90614_SUCCESS;
    else
        return   MLX90614_FAILURE;
}


/**
 * @brief       MLX90614_GetTemperatureSource ( MLX90614_vector_data_t* )
 *
 * @details     It gets the temperature source.
 *
 * @param[in]    NaN
 *
 * @param[out]   myTempSource:      Temperature source.
 *
 *
 * @return       Status of MLX90614_GetTemperatureSource.
 *
 *
 * @author      Manuel Caballero
 * @date        26/December/2017
 * @version     26/December/2017     The ORIGIN
 * @pre         NaN.
 * @warning     NaN.
 */
MLX90614::MLX90614_status_t  MLX90614::MLX90614_GetTemperatureSource ( MLX90614_vector_data_t* myTempSource )
{
    char         cmd[]       =   { MLX90614_CONFIG_REGISTER_1, 0, 0 };
    uint32_t     aux         =   0;


    // It gets the temperature source
    aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
    aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );


    myTempSource->TempSource   =   ( MLX90614_configregister1_temp_t )( cmd[0] & CONFIGREG1_TEMP_MASK );
    myTempSource->PEC          =   cmd[2];




    if ( aux == I2C_SUCCESS )
        return   MLX90614_SUCCESS;
    else
        return   MLX90614_FAILURE;
}


/**
 * @brief       MLX90614_SetTemperatureSource ( I2C_parameters_t , MLX90614_configregister1_temp_t )
 *
 * @details     It sets the temperature source.
 *
 * @param[in]    myTempSource:      Temperature source.
 *
 * @param[out]   NaN.
 *
 *
 * @return       Status of MLX90614_SetTemperatureSource.
 *
 *
 * @author      Manuel Caballero
 * @date        26/December/2017
 * @version     26/December/2017     The ORIGIN
 * @pre         NaN.
 * @warning     NaN.
 */
MLX90614::MLX90614_status_t  MLX90614::MLX90614_SetTemperatureSource ( MLX90614_configregister1_temp_t myTempSource )
{
    char         cmd[]       =   { MLX90614_CONFIG_REGISTER_1, 0, 0 };
    uint32_t     aux         =   0;
    uint32_t     ii          =   0;


    // It gets the IIR
    aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
    aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );

    // Erase EEPROM
    cmd[2]   =   cmd[1];                                                       // MSB
    cmd[1]   =   ( cmd[0] & ~CONFIGREG1_TEMP_MASK );                           // LSB
    cmd[0]   =   MLX90614_CONFIG_REGISTER_1;                                   // Command
    aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 3, false );

    // It takes EEPROM about 5ms to write/read
    do
    {
        cmd[0]   =   MLX90614_FLAGS;
        aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
        aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], 3 );
        ii++;                                                                                 // Increase the timeout
    }
    while ( ( ( cmd[0] & FLAG_EEBUSY_HIGH ) == FLAG_EEBUSY_HIGH ) && ( ii < MLX90614_TIMEOUT ) );


    // If TIMEOUT, exit with failure.
    if ( ii >= MLX90614_TIMEOUT )
        return MLX90614_FAILURE;
    else
    {
        // It gets the IIR
        aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
        aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );

        // Update the new value
        cmd[2]   =   cmd[1];                                                       // MSB
        cmd[1]   =   ( ( cmd[0] & ~CONFIGREG1_TEMP_MASK ) | myTempSource );        // LSB
        cmd[0]   =   MLX90614_CONFIG_REGISTER_1;                                   // Command
        aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 2, false );
    }




    if ( aux == I2C_SUCCESS )
        return   MLX90614_SUCCESS;
    else
        return   MLX90614_FAILURE;
}


/**
 * @brief       MLX90614_GetFLAGS ( MLX90614_vector_data_t* )
 *
 * @details     It gets the flags.
 *
 * @param[in]    NaN.
 *
 * @param[out]   myFlags:           Flags.
 *
 *
 * @return       Status of MLX90614_GetFLAGS.
 *
 *
 * @author      Manuel Caballero
 * @date        26/December/2017
 * @version     26/December/2017     The ORIGIN
 * @pre         NaN.
 * @warning     NaN.
 */
MLX90614::MLX90614_status_t  MLX90614::MLX90614_GetFLAGS ( MLX90614_vector_data_t* myFlags )
{
    char         cmd[]       =   { MLX90614_FLAGS, 0, 0 };
    uint32_t     aux         =   0;


    // It gets the flags
    aux      =   _i2c.write ( _MLX90614_Addr, &cmd[0], 1, true );
    aux      =   _i2c.read  ( _MLX90614_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );


    myFlags->Flags =   ( MLX90614_flags_t )cmd[0];
    myFlags->PEC   =   cmd[2];




    if ( aux == I2C_SUCCESS )
        return   MLX90614_SUCCESS;
    else
        return   MLX90614_FAILURE;
}
