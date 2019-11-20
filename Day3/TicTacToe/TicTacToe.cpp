#include <iostream>
#include <string>
using namespace std;
// all global variable
const int size_Board = 7;
const int winValue = 4;
string board[size_Board][size_Board];
string name1;
string name2;
int turn = 0;
int playerturn = 1;
int lastI;
int lastJ;
int isWin()
{
    cout << lastI << " " << lastJ << endl;
    // Vertical check
    int count = 0;
    int tempI = lastI;
    int tempJ = lastJ;
    // down
    for (tempI = lastI; tempI < size_Board - 1; tempI++)
    {
        if (board[tempI][tempJ] == board[tempI + 1][tempJ])
        {
            count++;
        }
        else
        {
            tempI += size_Board;
        }
    }

    // up
    for (tempI = lastI; tempI > 0; tempI--)
    {
        if (board[tempI][tempJ] == board[tempI - 1][tempJ])
        {
            count++;
        }
        else
        {
            tempI -= size_Board;
        }
    }

    if (count >= winValue - 1)
    {
        if (board[lastI][lastJ] == "O")
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    // Horizontal check
    count = 0;
    tempI = lastI;
    tempJ = lastJ;
    // down
    for (tempJ = lastJ; tempJ < size_Board - 1; tempJ++)
    {
        if (board[tempI][tempJ] == board[tempI][tempJ + 1])
        {
            count++;
        }
        else
        {
            tempJ += size_Board;
        }
    }

    // up
    for (tempJ = lastJ; tempJ > 0; tempJ--)
    {
        if (board[tempI][tempJ] == board[tempI][tempJ - 1])
        {
            count++;
        }
        else
        {
            tempJ -= size_Board;
        }
    }

    if (count >= winValue - 1)
    {
        if (board[lastI][lastJ] == "O")
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    // Diagonal Check

    count = 0;
    for (tempJ = lastJ, tempI = lastI; tempI > 0 && tempJ > 0; tempI--, tempJ--)
    {
        if (board[tempI][tempJ] == board[tempI - 1][tempJ - 1])
        {
            count++;
        }
        else
        {
            tempJ -= size_Board;
        }
    }
    for (tempJ = lastJ, tempI = lastI; tempI < size_Board - 1 && tempJ < size_Board - 1; tempI++, tempJ++)
    {
        if (board[tempI][tempJ] == board[tempI + 1][tempJ + 1])
        {
            count++;
        }
        else
        {
            tempJ += size_Board;
        }
    }
    if (count >= winValue - 1)
    {
        if (board[lastI][lastJ] == "O")
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    // Diagonal
    count = 0;
    for (tempJ = lastJ, tempI = lastI; tempI > 0 && tempJ < size_Board - 1; tempI--, tempJ++)
    {
        if (board[tempI][tempJ] == board[tempI - 1][tempJ + 1])
        {
            count++;
        }
        else
        {
            tempJ += size_Board;
            tempI -= size_Board;
        }
    }
    for (tempJ = lastJ, tempI = lastI; tempI < size_Board - 1 && tempJ > 0; tempI++, tempJ--)
    {
        if (board[tempI][tempJ] == board[tempI + 1][tempJ - 1])
        {
            count++;
        }
        else
        {
            tempJ += size_Board;
        }
    }
    if (count >= winValue - 1)
    {
        if (board[lastI][lastJ] == "O")
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    return 0;
}

void gamePlay()
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
            cout << "Your Turn " << name2 << " - " << turn - 1 << ": ";
            cin >> choice;
            playerturn = 1;
        }
    }

    // Set board value
    for (int i = 0; i < size_Board; i++)
    {
        for (int j = 0; j < size_Board; j++)
        {
            if (board[i][j] == choice)
            {
                lastJ = j;
                lastI = i;
                // Check turn
                // put the value opposite with the turn
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
    for (int i = 0; i < size_Board; i++)
    {
        for (int j = 0; j < size_Board; j++)
        {
            board[i][j] = to_string(i + 1) + to_string(j + 1);
        }
    }
}

void draw()
{
    cout << "\tTic Tac Toe\n\n";
    cout << name1 << "\tO\t" << name2 << "\tX\n\n";
    for (int j = 0; j < size_Board; j++)
    {
        cout << " _______";
    }
    cout << "\n";
    for (int i = 0; i < size_Board; i++)
    {
        for (int j = 0; j < size_Board; j++)
        {
            cout << "|\t";
        }
        cout << "|\n";

        for (int j = 0; j < size_Board; j++)
        {
            cout << "|  " << board[i][j] << "\t";
        }
        // cout << "|  " << board[i][0] << "\t|  " << board[i][1] << "\t|  " << board[i][2] << "\t|\n";
        cout << "|\n";

        for (int j = 0; j < size_Board; j++)
        {
            cout << "|_______";
        }
        cout << "|\n";
    }
}

bool introduction()
{
    int choice;
    cout << "Welcome To Tic-tac-toe game! Play with your way!\n";
    cout << "If you find any problem, ";
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
void generateWinBoard()
{
    board[0][0] = "X";
    board[1][1] = "X";
    board[2][2] = "X";
    board[3][3] = "X";
    board[4][4] = "X";
}
int main()
{
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
        gamePlay();
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
    else
    {
        cout << "It is a tieeeee match!!";
    }
}