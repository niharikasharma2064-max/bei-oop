
#include <iostream>
using namespace std;

class SoccerPlayer
{
    int jersey_no, goals, assists;

public:
    void getData()
    {
        cout << "Enter Jersey No, Goals and Assists: ";
        cin >> jersey_no >> goals >> assists;
    }

    int operator>(SoccerPlayer c1)
    {
        if ((goals + assists) > (c1.goals + c1.assists))
            return 1;
        else
            return 0;
    }

    void display()
    {
        cout << "\nJersey No: " << jersey_no;
        cout << "\nGoals: " << goals;
        cout << "\nAssists: " << assists;
        cout << "\nTotal Contribution: " << goals + assists << endl;
    }
};

int main()
{
    SoccerPlayer p1, p2;

    cout << "Enter details of Player 1:\n";
    p1.getData();

    cout << "\nEnter details of Player 2:\n";
    p2.getData();

    if (p1 > p2)
        cout << "\nPlayer 1 has more goals + assists.";
    else
        cout << "\nPlayer 2 has more or equal goals + assists.";
  cin.ignore(); 
    cin.get();  
    return 0;
}