#include <iostream>
#include <ctime>
#include <Windows.h>
#include <iomanip>

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
    cout << fixed << setprecision(2);

    int time;
    int ms = 1000;
    int second = 1;
    int minute = second * 60;
    int hour = minute * minute;
    int day = hour * 24;

    double wood = 0;
    double stone = 0;
    double iron = 0;

    double wood_in_second = 1;
    double stone_in_second = 0.1;
    double iron_in_second = 0.01;

    int variant;

//  START
    start:

    cout << "You have " << wood << " wood." << endl;
    cout << "You have " << stone << " stone." << endl;
    cout << "You have " << iron << " iron." << endl << endl;

    cout << "What to do?" << endl
         << "1 = Get resources." << endl
         << "2 = Go to the store." << endl;
    cin >> variant;
    cout << endl;

    if (variant == 1)
    {
        clear();
        int resource;

        cout << "What resource to mine?" << endl
             << "1 = Woods." << endl
             << "2 = Stone." << endl
             << "3 = Iron." << endl;
        cin >> resource;
        cout << endl;

        if (resource == 1)
        {
            clear();
            int firewood_variant;

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
                double wood_value = 5;

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
                        clear();
                        cout << "You answered correctly, and received " << wood_value << " wood!" << endl << endl;
                        wood += 5;
                        cout << endl;
                        system("pause");
                    }
                    else
                    {
                        clear();
                        cout << "Sorry, you answered incorrectly." << endl << endl;
                        cout << endl;
                        system("pause");
                    }
                }
                clear();
                goto start;
            }
            else
            {
                cout << "You entered the wrong option!" << endl << endl;
                cout << endl;

                system("pause");
                clear();
                goto start;
            }
        }
        else if (resource == 2)
        {
            clear();
            int stone_variant;

            cout << "Choose a way to get stone" << endl
                << "1 = Chopping stone(" << stone_in_second << " per second)." << endl
                << "2 = Earn stone by solving tasks." << endl;
            cin >> stone_variant;
            cout << endl;

            if (stone_variant == 1)
            {
                clear();

                cout << "How long does it take to chop stone?(in seconds):" << endl;
                cin >> time;
                cout << endl;
                clear();

                for (size_t i = 0; i < time; i++)
                {
                    Sleep(ms);
                    stone += stone_in_second;
                    cout << "You cut down " << stone_in_second << " stone(s)." << endl;
                }
                cout << endl;

                clear();
                goto start;
            }
            else if (stone_variant == 2)
            {
                int tasks;
                int random_value_1;
                int random_value_2;
                int value;
                double stone_value = 0.5;

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
                        clear();
                        cout << "You answered correctly, and received " << stone_value << " stone!" << endl << endl;
                        wood += 5;
                        cout << endl;
                        system("pause");
                    }
                    else
                    {
                        clear();
                        cout << "Sorry, you answered incorrectly." << endl << endl;
                        cout << endl;
                        system("pause");
                    }
                }
                clear();
                goto start;
            }
            else
            {
                cout << "You entered the wrong option!" << endl << endl;
                cout << endl;

                system("pause");
                clear();
                goto start;
            }
        }
        else if (resource == 3)
        {
            clear();
            int iron_variant;

            cout << "Choose a way to get iron" << endl
                << "1 = Chopping iron(" << iron_in_second << " per second)." << endl
                << "2 = Earn iron by solving tasks." << endl;
            cin >> iron_variant;
            cout << endl;

            if (iron_variant == 1)
            {
                clear();

                cout << "How long does it take to chop iron?(in seconds):" << endl;
                cin >> time;
                cout << endl;
                clear();

                for (size_t i = 0; i < time; i++)
                {
                    Sleep(ms);
                    iron += iron_in_second;
                    cout << "You cut down " << iron_in_second << " iron(s)." << endl;
                }
                cout << endl;

                clear();
                goto start;
            }
            else if (iron_variant == 2)
            {
                int tasks;
                int random_value_1;
                int random_value_2;
                int value;
                double iron_value = 0.5;

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
                        clear();
                        cout << "You answered correctly, and received " << iron_value << " iron!" << endl << endl;
                        wood += 5;
                        cout << endl;
                        system("pause");
                    }
                    else
                    {
                        clear();
                        cout << "Sorry, you answered incorrectly." << endl << endl;
                        cout << endl;
                        system("pause");
                    }
                }
                clear();
                goto start;
            }
            else
            {
                cout << "You entered the wrong option!" << endl << endl;
                cout << endl;

                system("pause");
                clear();
                goto start;
            }
        }
    }
    else if (variant == 2)
    {
        clear();
        int section;

        cout << "Select a store section:" << endl
             << "1 = Axes." << endl;
        cin >> section;
        cout << endl;

        if (section == 1)
        {
            clear();
            int axe;

            cout << "Select an ax to purchase:" << endl
                 << "1 = Wooden ax | Costs 50.00 firewood." << endl
                 << "2 = Wood-stone ax | Costs 35.00 firewood and 15.00 stones." << endl
                 << "3 = Stone ax | Costs 50.00 stone." << endl
                 << "4 = Stone-iron ax | Costs 35.00 stone and 15.00 iron." << endl
                 << "5 = Iron ax | Costs 50.00 iron" << endl;
            cout << endl;
            cin >> axe;

            switch (axe)
            {
            case 1:
                if (wood >= 50)
                {
                    wood -= 50;
                    wood_in_second += 2;
                    stone_in_second += 0.3;
                    iron_in_second += 0.05;

                    cout << "You have purchased a wooden ax!" << endl;

                    system("pause");
                    clear();
                    goto start;
                }
                else
                {
                    clear();

                    cout << "Unfortunately, you do not have enough resources for this ax!" << endl << endl;
                    cout << endl;

                    system("pause");
                    clear();
                    goto start;
                }
                break;
            case 2:
                if (wood >= 35 && stone >= 15)
                {
                    wood -= 35;
                    stone -= 15;
                    wood_in_second += 5;
                    stone_in_second += 1;
                    iron_in_second += 0.1;

                    cout << "You have purchased a wood-stone ax!" << endl;

                    system("pause");
                    clear();
                    goto start;
                }
                else
                {
                    clear();

                    cout << "Unfortunately, you do not have enough resources for this ax!" << endl << endl;
                    cout << endl;

                    system("pause");
                    clear();
                    goto start;
                }
                break;
            case 3:
                if (stone >= 50)
                {
                    stone -= 50;
                    wood_in_second += 10;
                    stone_in_second += 2.5;
                    iron_in_second += 0.4;

                    cout << "You have purchased a stone ax!" << endl;

                    system("pause");
                    clear();
                    goto start;
                }
                else
                {
                    clear();

                    cout << "Unfortunately, you do not have enough resources for this ax!" << endl << endl;
                    cout << endl;

                    system("pause");
                    clear();
                    goto start;
                }
                break;
            case 4:
                if (stone >= 35 && iron >= 15)
                {
                    stone -= 35;
                    iron -= 15;
                    wood_in_second += 18;
                    stone_in_second += 5;
                    iron_in_second += 1;

                    cout << "You have purchased a stone-iron ax!" << endl;

                    system("pause");
                    clear();
                    goto start;
                }
                else
                {
                    clear();

                    cout << "Unfortunately, you do not have enough resources for this ax!" << endl << endl;
                    cout << endl;

                    system("pause");
                    clear();
                    goto start;
                }
                break;
            case 5:
                if (iron >= 50)
                {
                    iron -= 50;
                    wood_in_second += 30;
                    stone_in_second += 10;
                    iron_in_second += 3;

                    cout << "You have purchased an iron ax!" << endl;

                    system("pause");
                    clear();
                    goto start;
                }
                else
                {
                    clear();

                    cout << "Unfortunately, you do not have enough resources for this ax!" << endl << endl;
                    cout << endl;

                    system("pause");
                    clear();
                    goto start;
                }
                break;
            default:
                clear();

                cout << "You entered the wrong option!" << endl << endl;
                cout << endl;

                system("pause");
                clear();
                goto start;
                break;
            }
        }
        else
        {
            clear();

            cout << "You entered the wrong option!" << endl << endl;
            cout << endl;

            system("pause");
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