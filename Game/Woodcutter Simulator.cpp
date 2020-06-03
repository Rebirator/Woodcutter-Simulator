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

//  START
    start:
    cout << "You have " << wood << " wood." << endl << endl;;

    cout << "What to do?" << endl
         << "1 = Chopping wood(" << wood_in_second << " per second)." << endl;
//         << "2 = Earn firewood by solving tasks" << endl;
    cin >> firewood_variant;
    cout << endl;

    if (firewood_variant == 1)
    {
        cout << "How long does it take to chop wood?(in seconds): " << endl;
        cin >> time;
        cout << endl;

        for (size_t i = 0; i < time; i++)
        {
            Sleep(ms);
            wood += wood_in_second;
            cout << "You cut down " << wood_in_second << " tree(s)." << endl;
        }
        cout << endl;

        goto start;
    }
}