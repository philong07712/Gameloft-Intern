#include "DengueVirus.cpp"
int main()
{
    Virus *v1 = new DengueVirus;
    Virus *v2 = new DengueVirus;
    cout << v1->getM_resistance();
    cout << "\n";
    cout << v2->getM_resistance();
    delete v1, v2;
}