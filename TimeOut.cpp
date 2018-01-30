#include "TimeOut.h"
#include "Arduino.h"
#define DEBUG_MODE false
TimeOut::TimeOut() :
	__limit(0),
	__startTime(0),
	__running(false)
{}

TimeOut::TimeOut(uint16_t limit = 0) :
	__limit(limit),
	__startTime(millis()),
	__running(bool(limit))	
{
#if DEBUG_MODE
Serial.print("constr\t__limit = ");
Serial.print(__limit);
Serial.print("\t__startTime = ");
Serial.print(__startTime);
Serial.print("\t__running = ");
Serial.println(__running);
#endif
}


bool TimeOut::check()
{
#if DEBUG_MODE
Serial.print(__running);
Serial.write(9);
Serial.print(millis()-__startTime);
Serial.write(9);
Serial.println(__limit);
#endif
	if ( __running  &&  (millis() - __startTime >= __limit) )
		return true;
	return false;
}

uint32_t TimeOut::remain()
{
	if (__running && !check()) return __startTime + __limit - millis() ;
	else return 0;
}

uint32_t TimeOut::reset()
{
	__startTime = millis();
	__running = true;
	return __limit;
}

uint32_t TimeOut::proceed()
{
	__startTime += __limit;
	__running    = bool(__limit);
	return (__startTime+__limit) - millis();
}

void TimeOut::stop()
{
	__running = false;
}


void TimeOut::operator = (uint32_t value)
{
	__startTime = millis();
	__limit = value;
	__running = true;
}

void TimeOut::operator *= (uint32_t value)
{
	__startTime = millis();
	__limit *= value;
}

