#include "Stepper.h"

int main(){
  wiringPiSetup();
  Stepper stepper(8,9,7,0);
  stepper.halfStep(512);
}
