#include "MyPoint.h"
#include <iostream>
#include <math.h>
using namespace std;
MyPoint::MyPoint() : mPosX(0), mPosY(0)
{
}
MyPoint::MyPoint(int x, int y) : mPosX(x), mPosY(y)
{
}

void MyPoint::Display()
{
    cout << "(" << this->mPosX << ", " << this->mPosY << ")";
}

int MyPoint::GetX()
{
    return this->mPosX;
}

int MyPoint::GetY()
{
    return this->mPosY;
}
void MyPoint::SetX(int x)
{
    this->mPosX = x;
}

void MyPoint::SetY(int y)
{
    this->mPosY = y;
}
float MyPoint::Distance(MyPoint p)
{
    float horizon = pow(p.GetX() - this->GetX(), 2);
    float vertical = pow(p.GetY() - this->GetY(), 2);
    return sqrt(horizon + vertical);
}