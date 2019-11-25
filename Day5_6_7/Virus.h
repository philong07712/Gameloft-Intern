#include "list"
using namespace std;
class Virus
{
    char *m_dna;
    int m_resistance;

public:
    Virus();                     //
    Virus(const Virus &);        //
    void LoadADNInformation();   //
    void ReduceResistance(int);  //
    char *getDna() const;      //
    int getResistance() const; //
    void setDna(char *);       //
    void setResistance(int);   //
    // pure virtual method
    virtual void DoBorn() = 0;
    virtual ~Virus(); 
    virtual list<Virus *> DoClone() = 0;
    virtual void DoDie() = 0;
    virtual void InitResistance() = 0;
};