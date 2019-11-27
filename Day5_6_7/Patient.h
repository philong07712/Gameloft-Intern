#pragma once
#include "Virus.h"
#include "DengueVirus.h"
#include "FluVirus.h"
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