#include "Virus.cpp"
class DengueVirus : public Virus
{
    char m_protein[4];
    public:
    DengueVirus();
    void DoBorn();
    Virus *DoClone();
    void DoDie();
    void InitResistance();
    ~DengueVirus();
};