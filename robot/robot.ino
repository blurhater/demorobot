
#include <Servo.h>
#include <Oscillator.h>
#include <RobotLib.h>

#define PIN_UR 6 //верхний правый
#define PIN_UL 10 //верхний левый
#define PIN_LR 5 //нижний правый
#define PIN_LL 11 //нижний левый

#define TRIM_UR   -7
#define TRIM_UL   -2
#define TRIM_LR   0
#define TRIM_LL  -14

RobotLib z;
Servo s;
int angle;

void setup()
{
  z.add(PIN_LL, PIN_LR, PIN_UL, PIN_UR);
  z.setTrims(TRIM_LL, TRIM_LR, TRIM_UL, TRIM_UR);
}

void loop()
{
  z.stop();
  z.walk(4, 2000, f);
  z.stop();
  delay(2000);
  z.turn(4, 2000, l);
  z.stop();
  delay(2000);
  z.strafe(4, 1000, r);
  z.stop();
  delay(2000);
  z.moonwalker(4, 1000, 30, l);
  z.stop();
  delay(2000);
  z.sox(4, 1000, 20);
  z.stop();
  delay(2000);
  z.swing(4, 1000, 15);
  z.stop();
  delay(2000);
  while (1);
}



