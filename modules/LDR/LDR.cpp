//=====[Libraries]=============================================================

#include "fire_alarm.h"
#include "mbed.h"
#include "LDR.h"


#define Dangerous_Gas_Level                    1000


AnalogIn LDR(A2);


float LDR_Level            = 0.0;



float LDR01(float analogRead)
{
        return (analogRead);
    }

float LDR_Read (){
    LDR_Level = LDR01(LDR);

    return LDR_Level;

}

void LDR_Reset()
{
    LDR_Level = 0.0;
}