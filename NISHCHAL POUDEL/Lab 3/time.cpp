#include <iostream>
using namespace std;

class Time {
    int day, hour, minute, second;
public:
    Time(int d=0, int h=0, int m=0, int s=0) : day(d), hour(h), minute(m), second(s) {}

    void addTime(Time t1, Time t2) {
        second = t1.second + t2.second;
        minute = t1.minute + t2.minute + (second / 60);
        second %= 60;

        hour = t1.hour + t2.hour + (minute / 60);
        minute %= 60;

        day = t1.day + t2.day + (hour / 24);
        hour %= 24;
    }

    void display() {
        cout << day << "d " << hour << "h " << minute << "m " << second << "s" << endl;
    }
};

int main() {
    Time t1(1, 10, 45, 50), t2(0, 15, 20, 30), t3;
    t3.addTime(t1, t2);
    
    cout << "Time 1: "; t1.display();
    cout << "Time 2: "; t2.display();
    cout << "Sum:    "; t3.display();
     cin.ignore(); // clears buffer
    cin.get();    // holds screen 
    return 0;
}