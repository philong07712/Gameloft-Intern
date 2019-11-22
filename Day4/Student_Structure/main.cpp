#include "ListStudent.cpp"
#include <fstream>
#include <sstream>

int menu()
{
    int choose;
    cout << "\n-------------------MENU-------------------\n";
    cout << "\t1. Input\n";
    cout << "\t2. Display\n";
    cout << "\t3. Save to file\n";
    cout << "\t4. Load from file\n";
    cout << "\t0. Exit\n";
    cout << "------------------------------------------\n";
    cout << "Choose: ";
    cin >> choose;
    return choose;
}

int main()
{
    ListStudent *list = new ListStudent;

    ifstream myfileLoad("FileLoad.txt");
    string line;
    string token;
    string tab = "\t\t";
    int addID;
    string addName;
    float addScore;
    ofstream myfile;
    while (true)
    {
        int choose = menu();
        switch (choose)
        {
        case 1:
            list->input();
            break;
        case 2:
            list->display();
            break;
        case 3:
            myfile.open("FileSave.txt");
            myfile << list->saveString();
            myfile.close();
            break;
        case 4:
            if (myfileLoad.is_open())
            {
                while (getline(myfileLoad, line))
                {
                    // Get ID
                    token = line.substr(0, line.find(tab));
                    line.erase(0, line.find(tab) + tab.length());
                    // Set ID from string to int
                    stringstream ss;
                    ss << token;
                    ss >> addID;
                    // Get Name from the txt file
                    token = line.substr(0, line.find(tab));
                    addName = token;
                    line.erase(0, line.find(tab) + tab.length());
                    // Get Score
                    token = line.substr(0, line.find("\n"));
                    line.erase(0, line.find(tab) + tab.length());
                    // Set score from string to Float
                    addScore = stod(token);
                    list->addStudent(addID, addName, addScore);
                }
                myfileLoad.close();
            }
            break;
        case 0:
            return 0;
        default:
            cout << "Wrong choice!!!!\n";
        }
    }
}