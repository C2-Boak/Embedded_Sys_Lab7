#include "arm_book_lib.h"
#include "bright_control.h"
#include "light_level_control.h"
#include "LDR.h"


#define LEDS_QUANTITY 3
#define TRANSITION_TIME 30.0f  
#define TICK_RATE 0.00001f       
#define TRANSITION_STEPS (int)(TRANSITION_TIME / TICK_RATE)  


PwmOut RGBLed[] = {(PB_1), (PA_0), (PD_12)};  
Ticker tickerBrightControl;



static int tickCounter = 0;

static float redValue = 1.0f;   
static float greenValue = 0.5f;  
static float blueValue = 0.0f;  
static int transitionPhase = 0;   



static void setPeriod(lightSystem_t light, float period);
static void tickerCallbackBrightControl();
static void updateLEDColor();   
static void resetTransition();  



void brightControlInit()
{
    tickerBrightControl.attach(tickerCallbackBrightControl, TICK_RATE); 

  
    RGBLed[0].write(redValue);   
    RGBLed[1].write(greenValue); 
    RGBLed[2].write(blueValue);  



}
void setDutyCycle(lightSystem_t light, float dutyCycle)
{
    
    RGBLed[light].write(dutyCycle);  
}

//=====[Implementations of private functions]==================================

static void setPeriod(lightSystem_t light, float period)
{
    // In case period adjustment is necessary, we can set it here.
}

static void tickerCallbackBrightControl()
{
    
    updateLEDColor();   
    LDR_Read(); 
    
    RGBLed[0].write(redValue - LDR_Level);   
    RGBLed[1].write(greenValue - LDR_Level); 
    RGBLed[2].write(blueValue - LDR_Level);  

   
    tickCounter++;
    if (tickCounter >= TRANSITION_STEPS) {
        resetTransition();
    }
}

static void updateLEDColor()

{

 
   
    if (transitionPhase == 0) { 
        redValue -= 1.0f / TRANSITION_STEPS;   
        greenValue += 1.0f / TRANSITION_STEPS; 
        blueValue += 1.0f / TRANSITION_STEPS;  
    }
    else {  
        redValue += 1.0f / TRANSITION_STEPS;
        greenValue -= 1.0f / TRANSITION_STEPS; 
        blueValue -= 1.0f / TRANSITION_STEPS;  
    }


    if (redValue > 1.0f) redValue = 1.0f;
    if (greenValue > 1.0f) greenValue = 1.0f;
    if (blueValue > 1.0f) blueValue = 1.0f;

    if (redValue < 0.0f) redValue = 0.0f;
    if (greenValue < 0.0f) greenValue = 0.0f;
    if (blueValue < 0.0f) blueValue = 0.0f;
}

static void resetTransition()
{
    
    tickCounter = 0;
    if (transitionPhase == 0) {
        transitionPhase = 1;  
    }
    else {
        transitionPhase = 0;  
    }
}