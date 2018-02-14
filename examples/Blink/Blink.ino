#define LED_BIT 0x20
#define LED_DDR DDRB
#define LED_PIN PINB

#include "TimeOut.h"
#define BLINK_TIME 500

#define ON_TIME 100
#define OFF_TIME 900

TimeOut timeout(BLINK_TIME);

void setup()
{
  LED_DDR |= LED_BIT;
}

void loop()
{
  
static bool ledState = false;

  if ( timeout.check() )
  {
    LED_PIN = LED_BIT;

//
    timeout.proceed();

  /*
  if (ledState)
    timeout = OFF_TIME;
  else
    timeout = ON_TIME;
  ledState ^= 1;
  */

  }
}