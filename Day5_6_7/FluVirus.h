#pragma once
#include "Virus.cpp"
class FluVirus : public Virus
{
    int m_color;

public:
    FluVirus();
    int getM_color();
    void setM_color(int);
    void DoBorn();
    Virus* DoClone();
    void DoDie();
    void InitResistance();
    ~FluVirus();
};