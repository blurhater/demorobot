#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include <pins_arduino.h>
#endif
#include "RobotLib.h"
#include <Oscillator.h>

void RobotLib::add(int LL, int LR, int UL, int UR)
{
    servo[0].attach(LL);
    servo[1].attach(LR);
    servo[2].attach(UL);
    servo[3].attach(UR);
}

void RobotLib::setTrims(int LL, int LR, int UL, int UR)
{
    servo[0].SetTrim(LL);//lower left (нижний левый)
    servo[1].SetTrim(LR);//lower right (нижний правый)
    servo[2].SetTrim(UL);//upper right (верхний правый)
    servo[3].SetTrim(UR);//upper left (верхний левый)
}

void RobotLib::move(int A[4], int O[4], int T, double phase[4], int steps)
{
    for (int i=0; i<4; i++)
    {
        servo[i].SetO(O[i]);
        servo[i].SetA(A[i]);
        servo[i].SetT(T);
        servo[i].SetPh(phase[i]);
    }
    double time=millis();
    for (double t=time; t<=T*steps+time; t=millis())
    {
        for (int i=0; i<4; i++)
        {
            servo[i].refresh();
        }
    }
    time=millis();
    for (double t=time; t<=time; t=millis())
    {
        for (int i=0; i<4; i++)
        {
            servo[i].refresh();
        }
    }
}

void RobotLib::stop()
{
    int A[4]= {0, 0, 0, 0};
    int O[4] = {25, 5, 0, 22.5};
    double phase[4] = {0, 0, 0, 6};
    move(A,O,500,phase,1);
}

void RobotLib::walk(int steps, int T, int dir)
{
    int A[4]= {30, 30, 20, 20};
    int O[4] = {25, 5, 4, 16.5};
    double phase[4] = {0, 0, DEG2RAD(dir * -90), DEG2RAD(dir * -90)};
    move(A, O, T, phase, steps);
}


void RobotLib::turn(int steps, int T, int dir)
{
    int A[4]= {30, 30, 20, 20};
    int O[4] = {25, 10, 4, 16.5};
    double phase[4] = {0, 0, DEG2RAD(-90), DEG2RAD(-90)};
    if (dir == l)
    {
        A[0] = 30;
        A[1] = 10;
    }
    else
    {
        A[0] = 10;
        A[1] = 30;
    }
    move(A, O, T, phase, steps);
}

void RobotLib::strafe(int steps, int T, int dir)
{
    int A[4]= {20, 20, 0, 0};
    int O[4] = {25, 10, 4, 16.5};
    double phase[4] = {0, DEG2RAD(dir* -60),0, 0 };
    move(A, O, T, phase, steps);
}

void RobotLib::sox(int steps, int T, int h)
{
    int A[4]= {0, 0, h, h};
    int O[4] = {25, 10, h, -h+22.5};
    double phase[4] = {0, 0, DEG2RAD(-90), DEG2RAD(90)};
    move(A, O, T, phase, steps);
}

void RobotLib::moonwalker(int steps, int T, int h, int dir)
{
    int A[4]= {0, 0, h, h};
    int O[4] = {25, 10, h/2+2, -h/2 +20.5};
    int phi = -dir * 90;
    double phase[4] = {0, 0, DEG2RAD(phi), DEG2RAD(-60 * dir + phi)};
    move(A, O, T, phase, steps);
}

void RobotLib::swing(int steps, int T, int h)
{
    int A[4]= {0, 0, h, h};
    int O[4] = {0, 0, h/2, -h/2};
    double phase[4] = {0, 0, DEG2RAD(0), DEG2RAD(0)};
    move(A, O, T, phase, steps);
}
