#include "Student.h"
#include <iostream>

Student::Student(int n_id = 0, string n_name = "Doan Xuan Hung", float n_score = 10.0)
{
    this->id = n_id;
    this->name = n_name;
    this->score = n_score;
}

Student::Student(const Student &s)
{
    this->id = s.id;
    this->name = s.name;
    this->score = s.score;
}

string Student::display() {
    string output = "";
    output += to_string(this->id);
    output += "\t\t";
    output += this->name;
    output += "\t\t";
    output += to_string(this->score);
    return output;
}

Student::~Student()
{
}