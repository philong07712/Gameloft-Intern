class Virus
{
    char *m_dna;
    int m_resistance;
public:
    Virus();//
    Virus(const Virus&);//
    void LoadADNInformation();//
    void ReduceResistance(int);//
    ~Virus();//
    char* getM_dna() const;//
    int getM_resistance() const;//
    void setM_dna(char*);//
    void setM_resistance(int);//
    // pure virtual method
    virtual void DoBorn() = 0;
    virtual Virus* DoClone() = 0;
    virtual void DoDie() = 0;
    virtual void InitResistance() = 0;
};