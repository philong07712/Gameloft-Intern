#include <iostream>
using namespace std;
typedef int *IntPtrType;
int main()
{
    IntPtrType ptr_a, ptr_b, *ptr_c;
    ptr_a = new int;
    *ptr_a = 3;
    ptr_b = ptr_a;
    // the pointer a will be set value as 3
    // pointer b point to pointer a, so pointer b will get
    // value of pointer a
    // so output will be 3 3
    cout << *ptr_a << " " << *ptr_b << "\n";
    ptr_b = new int;
    *ptr_b = 9;
    // pointer b will set value as 9
    // so output will be 3 9
    cout << *ptr_a << " " << *ptr_b << "\n";
    *ptr_b = *ptr_a;
    // pointer b will receive value of pointer a
    // so output will be 3 3
    cout << *ptr_a << " " << *ptr_b << "\n";
    delete ptr_a;
    ptr_a = ptr_b;
    // pointer has been delete
    // pointer a point to the same adress as pointer b (heap)
    // so output will be 3 3
    cout << *ptr_a << " " << *ptr_b << "\n";
    ptr_c = &ptr_a;
    // ptr c will point to pointer a
    // so *ptr_c will show address of pointer b point to (heap)
    // **ptr_c will show the value of pointer_a holding which is
    // pointer b value (heap) = 3
    // so output will be adress of the pointer a point to and value of it
    cout << *ptr_c << " " << **ptr_c << "\n";
    delete ptr_a;
    ptr_a = NULL;
    system("pause");
}