#include <iostream>
using namespace std;
int main()
{
int a[4] = {1, 2, 3, 4};
int *p = a;
int *p2 = new int;
delete p;
delete p2;
}