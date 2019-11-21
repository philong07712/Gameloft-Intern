#include "ListStudent.cpp"

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
            cout << "Save";
            break;
        case 4:
            cout << "Load";
            break;
        case 0:
            cout << "return";
            return 0;
        default:
            cout << "Wrong choice!!!!\n";
        }
    }
}