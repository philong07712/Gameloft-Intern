#pragma once
#include "Patient.h"
#include <time.h>
Patient::Patient()
{
    srand((int)time(0));
    this->InitResistance();
    this->DoStart();
}

void Patient::DoStart()
{
    int numV = 10 + rand() % 11;
    for (int i = 0; i < numV; i++)
    {
        // Random virus type
        int type = rand() % 2;
        // Case flu
        if (type == 0)
        {
            this->m_virusList.push_back(new FluVirus);
        }
        
        // case Dengue
        else
        {
            this->m_virusList.push_back(new DengueVirus);
        }
    }
    // this->m_virusList.push_back
    this->m_state = 1;
}
void Patient::InitResistance()
{
    int resit = 1000 + rand() % 8001;
    this->m_resistance = resit;
}


void Patient::TakeMedicine(int medicine_resitance)
{
    int resVirus = 0;
    for (int i = 0; i < this->m_virusList.size(); i++) {
        this->m_virusList[i]->ReduceResistance(medicine_resitance);
        if (this->m_virusList[i]->getM_resistance > 0) {
            // add cloned virus to the list
            this->m_virusList.push_back(this->m_virusList[i]->DoClone());
        }
    }
}

Patient::~Patient()
{
}