#include "TimeOut.h"
#include "Arduino.h"
TimeOut::TimeOut() :
	__limit(0),
	__startTime(0),
	__running(false)
{}

TimeOut::TimeOut(uint32_t limit = 0) :
	__limit(limit),
		#ifdef TIMEOUT_SET_MICROS
	__startTime(micros()),
		#else
	__startTime(millis()),
		#endif
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
		#ifdef TIMEOUT_SET_MICROS
	Serial.print(micros()-__startTime);
		#else
	Serial.print(millis()-__startTime);
		#endif
	Serial.write(9);
	Serial.println(__limit);
		#endif

		#ifdef TIMEOUT_SET_MICROS
	if ( __running  &&  (micros() - __startTime >= __limit) )
		#else
	if ( __running  &&  (millis() - __startTime >= __limit) )
		#endif
	{
		return true;
	}
	else
	{
	return false;
	}
}

uint32_t TimeOut::remain()
{
	if (__running && !check())
	{
			#ifdef TIMEOUT_SET_MICROS
		return __startTime + __limit - micros() ;
			#else
		return __startTime + __limit - millis() ;
			#endif
	}
	else
	{
		return 0;
	}
}

uint32_t TimeOut::reset()
{

		#ifdef TIMEOUT_SET_MICROS
	__startTime = micros();
		#else
	__startTime = millis();
		#endif
	__running = true;
	return __limit;
}

uint32_t TimeOut::proceed()
{
	__startTime += __limit;
	__running    = bool(__limit);
		#ifdef TIMEOUT_SET_MICROS
	return (__startTime+__limit) - micros();
		#else
	return (__startTime+__limit) - millis();
		#endif
}

void TimeOut::stop()
{
	__running = false;
}


void TimeOut::operator = (uint32_t value)
{
		#ifdef TIMEOUT_SET_MICROS
	__startTime = micros();
		#else
	__startTime = millis();
		#endif
	__limit = value;
	__running = true;
}

void TimeOut::operator *= (uint32_t value)
{
		#ifdef TIMEOUT_SET_MICROS
	__startTime = micros();
		#else
	__startTime = millis();
		#endif
	__limit *= value;
}

