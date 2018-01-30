#ifndef TIMEOUT
#define TIMEOUT

#include "Arduino.h"


class TimeOut {
  public:
	TimeOut();
    TimeOut(uint16_t limit);// initializes timeout from now with the limit in milliseconds
    boolean check();		// returns false if timeout is still running, tru if timeout (false if timeout is not set)
	uint32_t remain();		// retruns the remaining milliseconds
    uint32_t reset();		// resets the start time
	uint32_t proceed();		// like reset, but just adds the limit to the start time (use for periodic actions)
	void stop();			// stops Timeout ( check() will always return false )
    void operator = (uint32_t value);	// reinitializes timeout
	void operator *= (uint32_t value);  // reinitializes timeout with multiplyed limit (bewar of overflow)
  private:
	uint32_t __limit;
    uint32_t __startTime;
	bool __running;
};


#endif
