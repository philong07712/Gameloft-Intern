// short a[] = {5, 10, 15, 20, 25, 30}
// short *p = a;
# include <iostream>
using namespace std;
int main() {
    short a[] = {5, 10, 15, 20, 25, 30};
    short *p = a;
    p++;
    cout << a;
}

// a = 0x00affb84
// &a = 0x00affb84     
// *a = 5
// p = 0x00affb84
// &p = 0x00affb78
// *p = 5
// p + 1 = 0x00affb86
// (*p) + 1 = 6
// *(p + 1) = 10
// &p + 1 = 0x00affb82 (increase 1 time memory of that pointer = 4)
// &a + 1 = 0x00affb96 (increase 1 time memory of that array = 12)
// a++; a = &a[1] = 0x00affb86 (I am not so sure about this, when i run it called error)
// p++; p = 0x00affb86
