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
    list<Virus *>::iterator it;
    // iteator all the Viruses
    for (it = this->m_virusList.begin(); it != this->m_virusList.end(); it++)
    {
        (*it)->ReduceResistance(medicine_resitance);
        // Testing
        cout << "After take medicine : " << (*it)->getM_resistance() << endl;
        // Clone virus stage
        if ((*it)->getM_resistance() > 0)
        {
            list<Virus *> cloned = (*it)->DoClone();
            this->m_virusList.insert(it, cloned.begin(), cloned.end());
        }
    }
    // Testing after cloned
    for (it = this->m_virusList.begin(); it != this->m_virusList.end(); it++)
    {
        cout << "Finish cloned: " << (*it)->getM_resistance() << endl;
    }
}

Patient::~Patient()
{
}