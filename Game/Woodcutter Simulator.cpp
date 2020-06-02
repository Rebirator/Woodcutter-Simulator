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

start:
    cout << "У вас имеется " << wood << " древесины." << endl << endl;;

    cout << "Что делаем?" << endl
        << "1 = Рубить дрова(" << wood_in_second << " в секунду)." << endl
        << "2 = Заработать дрова решением заданий" << endl;
    cin >> firewood_variant;
    cout << endl;

    if (firewood_variant == 1)
    {
        cout << "Сколько рубить дрова?" << endl
            << "0 = 1 секунду." << endl
            << "1 = 10 секунд." << endl
            << "2 = Минуту." << endl
            << "3 = Час." << endl
            << "4 = День." << endl;
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
        }

        for (size_t i = 0; i < time; i++)
        {
            Sleep(ms);
            wood += wood_in_second;
            cout << "Вы срубили " << wood_in_second << " дерево(а)" << endl;
        }
        cout << endl;

        goto start;
    }
}