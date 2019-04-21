#include <wiringPi.h>
#include <iostream>
#include <vector>

struct StateSet
{
  bool states[4];

  StateSet(bool a, bool b, bool c, bool d)
    :states{a,b,c,d}
  {
  }
};

class Stepper {
private:
  int pins[4];
  int stage;
  std::vector<StateSet> states;
  void setPin(int pin, bool state);
public:
  Stepper(int pinA,int pinB,int pinC,int pinD);
  void halfStep(int noSteps);
};
