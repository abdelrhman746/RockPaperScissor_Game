#include <iostream>
#include <cstdlib>
using namespace std;

enum enScreenColor { Red = 1, Blue = 2, Green = 3, Yellow = 4, Black = 5 };
enum enComputerUserWinner{ComputerWin=1,UserWin=2,ComputerUserDraw=3};
enum enRockPaperScissor {Rock=1,Paper=2,Scissor=3};

struct stRoundResult
{
    int UserTurn;
    int ComputerTurn;
    int Winner;
    int RoundNumber;
    int UserWins;
    int ComputerWins;
    int ComputerUserDraws;
};

void RingBill(void)
{
    cout << "\a";
}

void ScreenColor(enScreenColor ScreenColor)
{
    if (ScreenColor == enScreenColor::Red)
    {
        system("color 4F");
    }
    else if (ScreenColor == enScreenColor::Blue)
    {
        system("color 1F");
    }
    else if (ScreenColor == enScreenColor::Green)
    {
        system("color 2F");
    }
    else if (ScreenColor == enScreenColor::Yellow)
    {
        system("color 6F");
    }
    else if (ScreenColor == enScreenColor::Black)
    {
        system("color 0F");
    }
    else
    {
        system("color 3F");
    }
}

int RandomNumber(int From, int To)
{
    //Function to generate a random number

    int randNum = rand() % (To - From + 1) + From;

    return randNum;
}

void GetComputerPlayTurn(stRoundResult &RoundResult)
{
    RoundResult.ComputerTurn= RandomNumber(1,3);
}

void GetUserPlayTurn(stRoundResult &RoundResult)
{
    
    do
    {
        cout << "Your Choice: [1]:Rock, [2]:Paper, [3]:Scissor  ?" << endl;
        cin >> RoundResult.UserTurn;
    } while (RoundResult.UserTurn>3);
    
}

void PrintPlayTurn(int ComputerUserTurn)
{
    (enRockPaperScissor)ComputerUserTurn;
    switch (ComputerUserTurn)
    {
        case enRockPaperScissor::Paper: cout << "Paper" << endl; break;
        case enRockPaperScissor::Rock: cout << "Rock" << endl; break;
        case enRockPaperScissor::Scissor:cout << "Scissor" << endl; break;
        default:
            break;
    }
}

void GetRoundResult(stRoundResult &RoundResult)
{
    
    if (RoundResult.UserTurn == enRockPaperScissor::Paper && RoundResult.ComputerTurn == enRockPaperScissor::Rock)
    {
        RoundResult.Winner = enComputerUserWinner::UserWin;
    }
    else if (RoundResult.UserTurn == enRockPaperScissor::Paper && RoundResult.ComputerTurn == enRockPaperScissor::Scissor)
    {
        RoundResult.Winner = enComputerUserWinner::ComputerWin;
    }
    else if (RoundResult.UserTurn == enRockPaperScissor::Paper && RoundResult.ComputerTurn == enRockPaperScissor::Paper)
    {
        RoundResult.Winner = enComputerUserWinner::ComputerUserDraw;
    }
    else if (RoundResult.UserTurn == enRockPaperScissor::Rock && RoundResult.ComputerTurn == enRockPaperScissor::Rock)
    {
        RoundResult.Winner = enComputerUserWinner::ComputerUserDraw;
    }
    else if (RoundResult.UserTurn == enRockPaperScissor::Rock && RoundResult.ComputerTurn == enRockPaperScissor::Scissor)
    {
        RoundResult.Winner = enComputerUserWinner::UserWin;
    }
    else if (RoundResult.UserTurn == enRockPaperScissor::Rock && RoundResult.ComputerTurn == enRockPaperScissor::Paper)
    {
        RoundResult.Winner = enComputerUserWinner::ComputerWin;
    }
    else if (RoundResult.UserTurn == enRockPaperScissor::Scissor && RoundResult.ComputerTurn == enRockPaperScissor::Rock)
    {
        RoundResult.Winner = enComputerUserWinner::ComputerWin;
    }
    else if (RoundResult.UserTurn == enRockPaperScissor::Scissor && RoundResult.ComputerTurn == enRockPaperScissor::Scissor)
    {
        RoundResult.Winner = enComputerUserWinner::ComputerUserDraw;
    }
    else if (RoundResult.UserTurn == enRockPaperScissor::Scissor && RoundResult.ComputerTurn == enRockPaperScissor::Paper)
    {
        RoundResult.Winner = enComputerUserWinner::UserWin;
    }
}

void PrintRoumdResult(stRoundResult &RoundResult)
{
    if (RoundResult.Winner == enComputerUserWinner::UserWin)
    {
        cout << "[ User ]" << endl;
        ScreenColor(enScreenColor::Green);
        RoundResult.UserWins++;
    }
    else if (RoundResult.Winner == enComputerUserWinner::ComputerWin)
    {
        cout << "[ Computer ]" << endl;
        RingBill();
        ScreenColor(enScreenColor::Red);
        RoundResult.ComputerWins++;
    }
    else if (RoundResult.Winner == enComputerUserWinner::ComputerUserDraw)
    {
        cout << "[ No Winner ]" << endl;
        ScreenColor(enScreenColor::Yellow);
        RoundResult.ComputerUserDraws++;
    }
}

void PrintRound(stRoundResult &RoundResult)
{
    cout << "_________________Round[" << RoundResult.RoundNumber << "}_________________" << endl;
    cout << "Player Choice  : ";
    PrintPlayTurn(RoundResult.UserTurn);
    cout << endl;
    cout << "Computer Choice: " ;
    PrintPlayTurn(RoundResult.ComputerTurn);
    cout << endl;
    cout << "Round Winner   :";
    PrintRoumdResult(RoundResult);
    cout << "__________________________________________" << endl;
}

int GetNumberOfRounds()
{
    int NumberOfRounds;
    do
    {
        cout << "How Many Rounds From 1 to 10 ?";
        cin >> NumberOfRounds;
    } while (!(NumberOfRounds > 0 && NumberOfRounds < 11));
    return NumberOfRounds;
}

string GetTheWinner(stRoundResult RoundResult)
{
    string TheWinner;
    if (RoundResult.UserWins > RoundResult.ComputerWins)
    {
        if (RoundResult.UserWins >= RoundResult.ComputerUserDraws)
        {
            TheWinner = "Player Wins";
            ScreenColor(enScreenColor::Green);
            return TheWinner;
        }
    }
    else if (RoundResult.ComputerWins > RoundResult.UserWins)
    {
        if (RoundResult.ComputerWins >= RoundResult.ComputerUserDraws)
        {
            TheWinner = "Computer Wins";
            RingBill();
            ScreenColor(enScreenColor::Red);
            return TheWinner;
        }
    }
    else 
    {
        TheWinner = "No Winner";
        ScreenColor(enScreenColor::Yellow);
        return TheWinner;
    }

    
}

void PrintGameOver(int NumberOfRounds, stRoundResult RoundResult, string TheWinner)
{
    cout << "\t\t\t\t_______________________________________________" << endl;
    cout << "\t\t\t\t          + + + Game Over + + +                " << endl;
    cout << "\t\t\t\t_______________________________________________" << endl;
    cout << "\t\t\t\t_____________[ Game Results ]__________________" << endl;
    cout << "\t\t\t\tGame Rounds          :";
    cout << NumberOfRounds << endl;
    cout << "\t\t\t\tPlayer Won Times     :";
    cout << RoundResult.UserWins << endl;
    cout << "\t\t\t\tComputer Won Times   :";
    cout << RoundResult.ComputerWins << endl;
    cout << "\t\t\t\tDraw Times           :";
    cout << RoundResult.ComputerUserDraws << endl;
    cout << "\t\t\t\tFinal Winner         :";
    cout << TheWinner << endl;
    cout << "\t\t\t\t_______________________________________________" << endl;
    
}

char CheckPlayAgain()
{
    char PlayAgain;
    cout << "Do you want to play again ? Y/N ";
    cin >> PlayAgain;
    return PlayAgain;
}

void ResetScreen() 
{
    system("cls");
    ScreenColor(enScreenColor::Black);
}

void RockPaperScissorGame()
{
    stRoundResult RoundResult;
    int UserTurn,Winner, ComputerTurn,NumberOfRounds;
    char PlayAgain = 'Y';
    string TheWinner = "";
    RoundResult.UserWins = 0, RoundResult.ComputerWins = 0, RoundResult.ComputerUserDraws = 0;
    int Counter = 0;
    RoundResult.RoundNumber = 0;
    while (PlayAgain == 'Y'||PlayAgain=='y')
    {
        ResetScreen();
        NumberOfRounds = GetNumberOfRounds();
        Counter = NumberOfRounds;
        while (Counter > 0)
        {
            cout << "Round [" << ++RoundResult.RoundNumber << "] Begins" << endl;
            GetUserPlayTurn(RoundResult);
            GetComputerPlayTurn(RoundResult);
            GetRoundResult( RoundResult);
            PrintRound(RoundResult);
            Counter--;
        }
        TheWinner = GetTheWinner(RoundResult);
        PrintGameOver(NumberOfRounds, RoundResult, TheWinner);
        PlayAgain = CheckPlayAgain();
        Counter = 0;
        RoundResult.RoundNumber = 0;
        RoundResult.UserWins = 0;
        RoundResult.ComputerWins = 0;
        RoundResult.ComputerUserDraws = 0;
    }
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    RockPaperScissorGame();
    
    
    return 0;
}