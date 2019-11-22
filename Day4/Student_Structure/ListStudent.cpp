#include "ListStudent.h"
#include <iostream>
#include <vector>
using namespace std;
ListStudent::ListStudent()
{
    this->size = 0;
}

ListStudent::ListStudent(const ListStudent &list)
{
    this->size = list.size;
    this->list_Student.clear();
    for (int i = 0; i < list.size; i++)
    {
        this->list_Student.push_back(list.list_Student[i]);
    }
}

bool ListStudent::isDuplicateID(int checkID)
{
    for (int i = 0; i < this->size; i++)
    {
        if (checkID == list_Student[i]->id)
        {
            return true;
        }
    }
    return false;
}
void ListStudent::addStudent(int n_id, string n_name, float n_Score) {
    this->size++;
    Student *s = new Student(n_id, n_name, n_Score);
    this->list_Student.push_back(s);
}
void ListStudent::input()
{
    int inputID;
    string inputName;
    float inputScore;
    bool check = true;
    do
    {
        cout << "ID: ";
        cin >> inputID;
        check = isDuplicateID(inputID);
    } while (check == true);

    cout << "Name: ";
    cin.ignore();
    getline(cin, inputName);
    do
    {
        cout << "Score: ";
        cin >> inputScore;
    } while (inputScore < 0 || inputScore > 10);
    Student *newS = new Student(inputID, inputName, inputScore);
    this->list_Student.push_back(newS);
    this->size++;
}

void ListStudent::display()
{
    cout << "ID\t\tFULL NAME\t\tSCORE\n";
    for (int i = 0; i < this->size; i++)
    {
        cout << list_Student[i]->display();
        cout << "\n";
    }
}

string ListStudent::saveString() {
    string save = "";
    for (int i = 0; i < this->size; i++) {
        save += list_Student[i]->display();
        save += "\n";
    }
    return save;
}
ListStudent::~ListStudent()
{
}