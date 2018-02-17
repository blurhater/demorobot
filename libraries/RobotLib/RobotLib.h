#ifndef RobotLib_h
#define RobotLib_h

#include <Oscillator.h>
#include <Servo.h>

#define f 1
#define b -1
#define l 1
#define r -1

class RobotLib
{
public:
    void add(int LL, int LR, int UL, int UR);
    void setTrims(int LL, int LR, int UL, int UR);
    void stop();
    void walk(int steps, int T, int dir);
    void turn(int steps, int T, int dir);
    void strafe(int steps, int T, int dir);
    void sox(int steps, int T, int h);
    void moonwalker(int steps, int T, int h, int dir);
    void swing(int steps, int T, int h);

private:
    Oscillator servo[4];
    int servo_trim[4];
    int servo_position[4];
    void move(int A[4], int O[4], int T, double phase[4], int steps);
};

#endif


