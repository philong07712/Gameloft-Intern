# include "Student.cpp"
# include "vector"

class ListStudent {
    public:
    int size;
    vector<Student> list_Student;
    ListStudent();
    ListStudent(const ListStudent&);
    void input();
    void display();
    bool isDuplicateID(int);
    ~ListStudent();
};