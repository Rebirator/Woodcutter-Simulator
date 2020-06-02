#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int time_variant;
    int time;
    int ms = 1000;
    int second = 1;
    int minute = second * 60;
    int hour = minute * minute;
    int day = hour * 24;

    int wood = 0;
    int wood_in_second = 1;

    int firewood_variant;

// START
start:
    cout << "You have " << wood << " wood." << endl << endl;;

    cout << "What to do?" << endl
         << "1 = Chopping wood(" << wood_in_second << " per second)." << endl;
//        << "2 = Earn firewood by solving tasks" << endl;
    cin >> firewood_variant;
    cout << endl;

    if (firewood_variant == 1)
    {
        cout << "How long does it take to chop wood?" << endl
            << "0 = 1 Second." << endl
            << "1 = 10 Seconds." << endl
            << "2 = 1 Minute." << endl
            << "3 = Hour." << endl
            << "4 = Day." << endl;
        cin >> time_variant;
        cout << endl;

        switch (time_variant)
        {
        case 0:
            time = second;
            break;
        case 1:
            time = second * 10;
            break;
        case 2:
            time = minute;
            break;
        case 3:
            time = hour / 10;
            break;
        case 4:
            time = day / 24 / 3;
            break;
        default:
            cout << "You entered the wrong option, return to the beginning.\n\n" << endl;
//          YES, I WILL USE IT!
            goto start;
        }

        for (size_t i = 0; i < time; i++)
        {
            Sleep(ms);
            wood += wood_in_second;
            cout << "You cut down " << wood_in_second << " tree(s)." << endl;
        }
        cout << endl;

//      YES, I WILL USE IT!
        goto start;
    }
}