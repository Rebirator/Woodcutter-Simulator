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

void pause()
{
    system("pause");
    clear();
}

int main()
{
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

    //profile variables
    //axes
    string axe[6]{ "Old wooden", "Wooden", "Wood-stone", "Stone", "Stone-iron", "Iron" };
    string axs = axe[0];
    //pickaxes
    string pickaxe[7]{ "None", "Old wooden", "Wooden", "Wood-stone", "Stone", "Stone-iron", "Iron" };
    string pickaxs = pickaxe[0];


    int variant;

//  START
    start:

    cout << "You have " << wood << " wood." << endl;
    cout << "You have " << stone << " stone." << endl;
    cout << "You have " << iron << " iron." << endl << endl;

    cout << "What to do?" << endl
         << "1 = Get resources." << endl
         << "2 = Go to the store.\n" << endl
         << "0 = My profile." << endl;
    cin >> variant;
    cout << endl;

    // RESOURCES
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

            // FIREWOOD
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
                    cout << "You cut down " << wood_in_second << " wood(s)." << endl;
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

                pause();
                goto start;
            }
        }
        // STONE
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

                pause();
                goto start;
            }
        }
        // IRON
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
                        pause();
                    }
                    else
                    {
                        clear();
                        cout << "Sorry, you answered incorrectly." << endl << endl;
                        cout << endl;
                        pause();
                    }
                }
                clear();
                goto start;
            }
            else
            {
                cout << "You entered the wrong option!" << endl << endl;
                cout << endl;

                pause();
                goto start;
            }
        }
    }
    // STORE
    else if (variant == 2)
    {
        clear();
        int section;

        cout << "Select a store section:" << endl
             << "1 = Axes." << endl
             << "2 = Pickaxes." << endl;
        cin >> section;
        cout << endl;

     // AXES
        if (section == 1)
        {
            clear();
            int ax;

            cout << "Select an ax to purchase:" << endl << endl
                 << "1 = Wooden ax:" << endl
                 << "Price: 50.00 firewood." << endl
                 << "Gives +2.00 wood per second." << endl << endl

                 << "2 = Wood-stone ax:" << endl
                 << "Price: 35.00 firewood and 15.00 stones." << endl
                 << "Gives +5.00 wood per second." << endl << endl

                 << "3 = Stone ax:" << endl
                 << "Price: 50.00 stone." << endl
                 << "Gives +10.00 wood per second." << endl << endl

                 << "4 = Stone-iron ax:" << endl
                 << "Price: 35.00 stone and 15.00 iron." << endl
                 << "Gives +18.00 wood per second." << endl << endl

                 << "5 = Iron ax:" << endl
                 << "Price: 50.00 iron." << endl
                 << "Gives +30.00 wood per second." << endl
                 << endl;
            cout << endl;
            cin >> ax;

            switch (ax)
            {
            case 1:
                if (wood >= 50.00)
                {
                    wood -= 50.00;
                    wood_in_second += 2;
                    axs = axe[1];

                    cout << "You have purchased a wooden ax!" << endl;

                    pause();
                    goto start;
                }
                else
                {
                    clear();

                    cout << "Unfortunately, you do not have enough resources for this ax!" << endl << endl;
                    cout << endl;

                    pause();
                    goto start;
                    break;
                }
                break;
            case 2:
                if (wood >= 35.00 && stone >= 15.00)
                {
                    wood -= 35.00;
                    stone -= 15.00;
                    wood_in_second += 5;
                    axs = axe[2];

                    cout << "You have purchased a wood-stone ax!" << endl;

                    pause();
                    goto start;
                }
                else
                {
                    clear();

                    cout << "Unfortunately, you do not have enough resources for this ax!" << endl << endl;
                    cout << endl;

                    pause();
                    goto start;
                    break;
                }
                break;
            case 3:
                if (stone >= 50.00)
                {
                    stone -= 50.00;
                    wood_in_second += 10;
                    axs = axe[3];

                    cout << "You have purchased a stone ax!" << endl;

                    pause();
                    goto start;
                }
                else
                {
                    clear();

                    cout << "Unfortunately, you do not have enough resources for this ax!" << endl << endl;
                    cout << endl;

                    pause();
                    goto start;
                    break;
                }
                break;
            case 4:
                if (stone >= 35.00 && iron >= 15.00)
                {
                    stone -= 35.00;
                    iron -= 15.00;
                    wood_in_second += 18;
                    axs = axe[4];

                    cout << "You have purchased a stone-iron ax!" << endl;

                    pause();
                    goto start;
                }
                else
                {
                    clear();

                    cout << "Unfortunately, you do not have enough resources for this ax!" << endl << endl;
                    cout << endl;

                    pause();
                    goto start;
                    break;
                }
                break;
            case 5:
                if (iron >= 50.00)
                {
                    iron -= 50.00;
                    wood_in_second += 30.00;
                    axs = axe[5];

                    cout << "You have purchased an iron ax!" << endl;

                    pause();
                    goto start;
                }
                else
                {
                    clear();

                    cout << "Unfortunately, you do not have enough resources for this ax!" << endl << endl;
                    cout << endl;

                    pause();
                    goto start;
                    break;
                }
            default:
                clear();

                cout << "You entered the wrong option!" << endl << endl;
                cout << endl;

                pause();
                goto start;
                break;
            }
        }
     // PICKAXES
        if (section == 2)
        {
            clear();
            int pickax;

            cout << "Select an ax to purchase:" << endl << endl
                << "1 = Old wooden pickax:" << endl
                << "Price: 50.00 firewood." << endl
                << "Gives +0.10 stone per second." << endl << endl

                << "2 = Wooden pickax:" << endl
                << "Price: 150 firewood." << endl
                << "Gives +0.50 stone per second." << endl << endl

                << "3 = Wood-stone pickax:" << endl
                << "Price: 125.00 firewood and 25.00 stones." << endl
                << "Gives +1.00 stone and +0.10 iron per second." << endl << endl

                << "4 = Stone pickax:" << endl
                << "Price: 150 stone." << endl
                << "Gives +3.00 stone and +0.70 iron per second." << endl << endl

                << "5 = Stone-iron pickax:" << endl
                << "Price: 100.00 stone and 50.00 iron." << endl
                << "Gives +5.00 stone and +1.25 iron per second." << endl << endl

                << "6 = Iron pickax:" << endl
                << "Price: 150.00 iron." << endl
                << "Gives +10.00 stone and +3.00 iron per second." << endl
                << endl;
            cout << endl;
            cin >> pickax;

            switch (pickax)
            {
            case 1:
                if (wood >= 50.00)
                {
                    wood -= 50.00;
                    stone_in_second = 0.10;
                    pickaxs = pickaxe[1];

                    cout << "You have purchased a old wooden pickax!" << endl;

                    pause();
                    goto start;
                }
                else
                {
                    clear();

                    cout << "Unfortunately, you do not have enough resources for this pickax!" << endl << endl;
                    cout << endl;

                    pause();
                    goto start;
                    break;
                }
                break;
            case 2:
                if (wood >= 150)
                {
                    wood -= 150;
                    stone_in_second = 0.50;
                    pickaxs = pickaxe[2];

                    cout << "You have purchased a wooden pickax!" << endl;

                    pause();
                    goto start;
                }
                else
                {
                    clear();

                    cout << "Unfortunately, you do not have enough resources for this pickax!" << endl << endl;
                    cout << endl;

                    pause();
                    goto start;
                    break;
                }
                break;
            case 3:
                if (wood >= 125.00 && stone >= 25.00)
                {
                    wood -= 125.00;
                    stone -= 25.00;
                    stone_in_second = 1.00;
                    iron_in_second = 0.10;
                    pickaxs = pickaxe[3];

                    cout << "You have purchased a wood-stone pickax!" << endl;

                    pause();
                    goto start;
                }
                else
                {
                    clear();

                    cout << "Unfortunately, you do not have enough resources for this pickax!" << endl << endl;
                    cout << endl;

                    pause();
                    goto start;
                    break;
                }
                break;
            case 4:
                if (stone >= 150.00)
                {
                    stone -= 150.00;
                    stone_in_second = 3.00;
                    iron_in_second = 0.70;
                    pickaxs = pickaxe[4];

                    cout << "You have purchased a stone pickax!" << endl;

                    pause();
                    goto start;
                }
                else
                {
                    clear();

                    cout << "Unfortunately, you do not have enough resources for this pickax!" << endl << endl;
                    cout << endl;

                    pause();
                    goto start;
                    break;
                }
                break;
            case 5:
                if (stone >= 100.00 && iron > 50.00)
                {
                    stone -= 100.00;
                    iron -= 50.00;
                    stone_in_second = 5.00;
                    iron_in_second = 1.25;
                    pickaxs = pickaxe[5];

                    cout << "You have purchased an stone-iron pickax!" << endl;
                    
                    pause();
                    goto start;
                }
                else
                {
                    clear();

                    cout << "Unfortunately, you do not have enough resources for this pickax!" << endl << endl;
                    cout << endl;

                    pause();
                    goto start;
                    break;
                }
                break;
            case 6:
                if (iron >= 150.00)
                {
                    iron -= 150.00;
                    stone_in_second = 10.00;
                    iron_in_second = 3.00;
                    pickaxs = pickaxe[6];

                    cout << "You have purchased an iron pickax!" << endl;

                    pause();
                    goto start;
                }
                else
                {
                    clear();

                    cout << "Unfortunately, you do not have enough resources for this pickax!" << endl << endl;
                    cout << endl;

                    pause();
                    goto start;
                    break;
                }
                break;
            default:
                clear();

                cout << "You entered the wrong option!" << endl << endl;
                cout << endl;

                pause();
                goto start;
                break;
            }
        }
        else
        {
            clear();

            cout << "You entered the wrong option!" << endl << endl;
            cout << endl;

            pause();
            goto start;
        }
    }
    else if (variant == 0)
    {
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

    cout << endl;
    pause();
}