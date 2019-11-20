// Why should we use delete?
// - because when we use delete we will fully delete a value located at heap
// - Not take that value as a garbage later and slow down the computer
// When we use delele?
// - when we use a pointer to allocate a value at heap memory
// - after we done, we need to delete it to not make it as a garbage later.
// Different between delete and delete[]
// - I think the most important is delete[] use for array.
// - When we use delete to an array, it will not fully deallcote the array.
// Demo:

# include <iostream>
using namespace std;

int main() {
    int *a = new int[3];
    int *b = new int;
    delete[] a;
    delete b;
}