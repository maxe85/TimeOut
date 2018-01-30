#include "TimeOut.h"

TimeOut example, demo(1000);
uint8_t demoIndex = 0;

void setup() 
{
  
  Serial.begin(9600);
    while(!Serial);
  
  Serial.println("TimeOut example;\t// used the void constructor");
  // no delay needed here, the demo timout does this job
}

void loop()
{
  if (demo.check())
  {
    demo.reset();
    
    Serial.print("example.check() = ");
    Serial.print(example.check());
    Serial.print(",\tremain() = ");
    Serial.println(example.remain());
    
    demoIndex++;
    
    switch (demoIndex)
    {
      case 4:
        Serial.println("example = TimeOut(2002)");
        example = TimeOut(2002);
        break;

      case 8:
      Serial.println("example = 4002");
        example = 4002;
        break;

      case 14:
        Serial.print("example.reset() = ");
        Serial.println(example.reset());
        break;

      case 20:
        Serial.print("example.proceed() = ");
        Serial.println(example.proceed());
        break;

      case 30:
        Serial.println("example.stop()");
        example.stop();
        break;

      case 35:
        Serial.println("terminat that demo with: while(!example.check()) - aka while(true)");
        while(!example.check());
    }
  
  }
}
