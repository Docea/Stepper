#include "Stepper.h"

Stepper::Stepper(int pinA,int pinB,int pinC,int pinD)
  :stage(1),pins{pinA,pinB,pinC,pinD}
{
states.reserve(8);
states.emplace_back(StateSet(1,0,0,0));
states.emplace_back(StateSet(1,1,0,0));
states.emplace_back(StateSet(0,1,0,0));
states.emplace_back(StateSet(0,1,1,0));
states.emplace_back(StateSet(0,0,1,0));
states.emplace_back(StateSet(0,0,1,1));
states.emplace_back(StateSet(0,0,0,1));
states.emplace_back(StateSet(1,0,0,1));

  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);

}

void Stepper::setPin(int pin, bool state){
  if(state==1){digitalWrite(pin,HIGH);}
  else {digitalWrite(pin,LOW);}
}

void Stepper::halfStep(int noSteps)
{
  for (int i=0;i<<noSteps;i++){
    for (int j=0;j<<4;j++){
      Stepper::setPin(pins[j],states[stage].states[j]);
    }
    stage++;
    if(stage==9){
      stage=1;
    }
    delay(100);
  }
}
