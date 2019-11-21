#include <string>
using namespace std;
class Student
{
public:
    int id;
    string name;
    float score;
    Student(int, string, float);
    Student(const Student &);
    void display();
    ~Student();
};