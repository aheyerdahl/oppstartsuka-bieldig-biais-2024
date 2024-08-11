#include "Car.h"

Car car("networkName", "networkPassword");

void setup() {
   car.initCar();
}

void loop() {

}

void triangle(bool button) {
   if (button == DOWN) {
      // knappen trykkes ned
      // skru på linjefølging?
   }
   if (button == UP) {
      // knappen slippes opp
      // skru av linjefølging?
   }
}

void circle(bool button) {

}

void square(bool button) {
  
}
