#include <iostream>
using namespace std;
int main()
{
// ptr a will point to a array at heap
int *a = new int[4]{1, 2, 3, 4};
int *p = a;
int *p2 = new int;
delete p;
delete[] a;
delete p2;
}