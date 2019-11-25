#pragma once
#include "Virus.cpp"
class DengueVirus : public Virus
{
    char m_protein[4];

public:
    DengueVirus();
    char *getM_protein();
    void setM_protein(char*);
    //
    void DoBorn();
    list<Virus*> DoClone();
    void DoDie();
    void InitResistance();
    ~DengueVirus();
};