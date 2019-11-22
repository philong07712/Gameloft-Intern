#pragma once
#include "Virus.cpp"
class FluVirus : public Virus
{
    int m_color;

public:
    void DoBorn();
    void DoClone();
    void DoDie();
    void InitResistance();
};