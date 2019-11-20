#include <bits/stdc++.h>
using namespace std;
// all global variable
string board[3][3];
string name1;
string name2;
int turn = 0;
int playerturn = 1;

int isWin()
{
    // kiem tra hang ngang
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
        {
            if (board[i][0] == "O")
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
    // kiem tra hang doc
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == board[1][j] &&
            board[1][j] == board[2][j])
        {
            if (board[0][j] == "O")
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
    // kiem tra hang nghieng
    // nghieng khi i = j
    int i = 0;
    if (board[i][i] == board[i + 1][i + 1] &&
        board[i + 1][i + 1] == board[i + 2][i + 2])
    {
        if (board[i][i] == "O")
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
    {
        if (board[0][2] == "O")
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    if (turn == 5) {
        return 3;
    }


    return 0;
}
void Gameplay()
{
    string choice;
    if (playerturn == 1)
    {
        cout << "Your Turn " << name1 << " - " << turn << ": ";
        cin >> choice;
        playerturn = 2;
        turn++;
    }
    else
    {
        if (playerturn == 2)
        {
            cout << "Your Turn  " << name2 << " - " << turn - 1 << ": ";
            cin >> choice;
            playerturn = 1;
        }
    }

    // Set gia tri len board
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == choice)
            {
                // Kiem tra xem turn ai, va
                // dat gia tri nguoc lai voi turn do
                if (playerturn == 2)
                {
                    board[i][j] = "O";
                }
                else
                    board[i][j] = "X";
                return;
            }
        }
    }
}

void generateBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = to_string(i + 1) + to_string(j + 1);
        }
    }
}

void draw()
{
    cout << "\tTic Tac Toe\n\n";
    cout << name1 << "\tO\t" << name2 << "\tX\n\n";
    cout << " _______________________\n";
    cout << "|\t|\t|\t|\n";
    cout << "|" << board[0][0] << "\t|" << board[0][1] << "\t|" << board[0][2] << "\t|\n";
    cout << "|_______|_______|_______|\n";
    cout << "|\t|\t|\t|\n";

    cout << "|" << board[1][0] << "\t|" << board[1][1] << "\t|" << board[1][2] << "\t|\n";
    cout << "|_______|_______|_______|\n";
    cout << "|\t|\t|\t|\n";

    cout << "|" << board[2][0] << "\t|" << board[2][1] << "\t|" << board[2][2] << "\t|\n";
    cout << "|_______|_______|_______|\n\n\n";
}

bool introduction()
{
    int choice;
    cout << "Welcome To Tic-tac-toe game! Play with your way!\n";
    cout << "If you find any problem";
    cout << "please contact philong07712@gmail.com\n\n";
    cout << "SELECT YOUR MODE(1 - PLAY GAME, OTHERS - EXIT GAME):\n";
    cin >> choice;
    if (choice != 1)
    {
        return false;
    }
    cout << "Enter Player 1 Name: ";
    cin >> name1;
    cout << "Enter Player 2 Name: ";
    cin >> name2;
    cout << "\n";
    return true;
}

int main()
{
    // start Game
    bool startGame = introduction();
    if (startGame == false)
    {
        return 0;
    }

    generateBoard();
    draw();
    int check = 0;
    while (check == 0)
    {
        Gameplay();
        draw();
        check = isWin();
    }
    // Congratulation winner
    if (check == 1)
    {
        cout << "Congratulation " << name1 << " has won";
    }
    else if (check == 2)
    {
        cout << "Congratulation " << name2 << " has won";
    }
    else {
        cout << "It is a tieeeee match!!";
    }
}