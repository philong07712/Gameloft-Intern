#pragma once
#include "Virus.cpp"
#include "DengueVirus.cpp"
#include "FluVirus.cpp"
#include <vector>
using namespace std;
class Patient
{
    int m_resistance;
    list<Virus *> m_virusList;
    int m_state;

public:
    Patient();
    void InitResistance();
    void DoStart();
    void TakeMedicine(int);
    void DoDie();
    int GetState();
    ~Patient();
};