//=====[Libraries]=============================================================

#include "../arm_book_lib.h"

#include "smart_home_system.h"

#include "../alarm/alarm.h"
#include "../user_interface/user_interface.h"
#include "../fire_alarm/fire_alarm.h"
#include "../intruder_alarm/intruder_alarm.h"
#include "../pc_serial_com/pc_serial_com.h"
#include "../event_log/event_log.h"
#include "../motion_sensor/motion_sensor.h"
#include "../motor/motor.h"
#include "../gate/gate.h"
#include "../light_system/light_system.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void smartHomeSystemInit()
{
    userInterfaceInit();
    alarmInit();
    fireAlarmInit();
    intruderAlarmInit();
    pcSerialComInit();
    motorControlInit();
    gateInit();
    lightSystemInit();
}

void smartHomeSystemUpdate()
{
    userInterfaceUpdate();
    fireAlarmUpdate();
    intruderAlarmUpdate();
    alarmUpdate();
    eventLogUpdate();
    pcSerialComUpdate();
    motorControlUpdate();
    lightSystemUpdate();
    delay(SYSTEM_TIME_INCREMENT_MS);
}

//=====[Implementations of private functions]==================================
