#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

void clear() {
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
    
    Sleep(100);
}

int main()
{
//    setlocale(LC_ALL, "RU");
    srand(time(NULL));

    int time;
    int ms = 1000;
    int second = 1;
    int minute = second * 60;
    int hour = minute * minute;
    int day = hour * 24;

    int wood = 0;
    int wood_in_second = 1;

    int variant;
    int firewood_variant;

//  START
    start:

    cout << "You have " << wood << " wood." << endl << endl;;

    cout << "What to do?" << endl
         << "1 = Get wood." << endl
         << "2 = Go to the store." << endl;
    cin >> variant;
    cout << endl;

    if (variant == 1)
    {
        clear();

        cout << "Choose a way to get firewood" << endl
             << "1 = Chopping wood(" << wood_in_second << " per second)." << endl
             << "2 = Earn firewood by solving tasks." << endl;
        cin >> firewood_variant;
        cout << endl;

        if (firewood_variant == 1)
        {
            clear();

            cout << "How long does it take to chop wood?(in seconds):" << endl;
            cin >> time;
            cout << endl;
            clear();

            for (size_t i = 0; i < time; i++)
            {
                Sleep(ms);
                wood += wood_in_second;
                cout << "You cut down " << wood_in_second << " tree(s)." << endl;
            }
            cout << endl;

            clear();
            goto start;
        }
        else if (firewood_variant == 2)
        {
            int tasks;
            int random_value_1;
            int random_value_2;
            int value;
            int wood_value = 5;

            cout << "How many tasks do you want to complete?:" << endl;
            cin >> tasks;
            cout << endl;

            for (size_t i = 0; i < tasks; i++)
            {
                random_value_1 = rand() % 100;
                random_value_2 = rand() % 100;

                cout << "How much is " << random_value_1 << " + " << random_value_2 << "?" << endl;
                cin >> value;
                cout << endl;

                if (random_value_1 + random_value_2 == value)
                {
                    cout << "You answered correctly, and received " << wood_value << " wood!" << endl << endl;
                    wood += 5;
                    cout << endl;
                }
                else
                {
                    cout << "Sorry, you answered incorrectly." << endl << endl;
                    cout << endl;
                }
            }
            clear();
            goto start;
        }
        else
        {
            cout << "You entered the wrong option!" << endl << endl;
            cout << endl;
            clear();
            goto start;
        }
    }
    else
    {
        cout << "You entered the wrong option!" << endl << endl;
        cout << endl;
        clear();
        goto start;
    }

    cout << endl;
    system("pause");
}