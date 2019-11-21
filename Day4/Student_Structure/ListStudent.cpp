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

void ListStudent::input()
{
    this->size++;
    int inputID;
    string inputName;
    float inputScore;
    cout << "ID: ";
    cin >> inputID;
    cout << "Name: ";
    cin.ignore();
    getline(cin, inputName);
    do
    {
        cout << "Score: ";
        cin >> inputScore;
    } while (inputScore < 0 || inputScore > 10);
    Student newS(inputID, inputName, inputScore);
    this->list_Student.push_back(newS);
}

void ListStudent::display()
{
    cout << "ID\t\tFULL NAME\t\tSCORE\n";
    for (int i = 0; i < this->size; i++)
    {
        list_Student[i].display();
        cout << "\n";
    }
}

ListStudent::~ListStudent()
{
}