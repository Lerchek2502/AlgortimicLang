#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct pipe {
    string name;
    int lenght;
    int diametr;
    bool repair;
};

struct station {
    string name;
    int countWS;
    int actWS;
    float eff;
};

int Take_Int(int b) {
    int buff;
    cin >> buff;
    while ((cin.fail()) || (buff < 0) || (buff > b) || (cin.get() != '\n')) {
        cin.clear();
        cin.ignore(1000000, '\n');
        cout << "Введите корректное число: ";
        cin >> buff;
    }
    return buff;
}

float Take_Float(float b) {
    float buff;
    cin >> buff;
    while ((cin.fail()) || (buff < 0) || (buff > b) || (cin.get() != '\n')) {
        cin.clear();
        cin.ignore(1000000, '\n');
        cout << "Введите корректное число: ";
        cin >> buff;
    }
    return buff;
}

void disp_menu() {
    system("cls");
    cout << "1. Добавить трубу\n";
    cout << "2. Добавить КС\n";
    cout << "3. Просмотр всех объектов\n";
    cout << "4. Редактировать трубу\n";
    cout << "5. Редактировать КС\n";
    cout << "6. Сохранить\n";
    cout << "7. Загрузить\n";
    cout << "0. Выход\n";
    cout << "\nВыберите действие - ";
}

pipe SetPipe() {
    pipe Item;
    system("cls");
    cout << "Добавление трубы\n";
    cout << "Имя: ";
    getline(cin, Item.name);
    cout << "Длинна (км): ";
    Item.lenght = Take_Int(1000000);
    while (Item.lenght <= 0) {
        cout << "Длинна должна быть больше 0!" << endl;
        Item.lenght = Take_Int(1000000);
    }
    cout << "Диаметр (см): ";
    Item.diametr = Take_Int(1000000);
    while (Item.diametr <= 0) {
        cout << "Диаметр должен быть больше 0!" << endl;
        Item.diametr = Take_Int(1000000);
    }
    cout << "Ремонт (0 - Нет или 1 - Да): ";
    Item.repair = Take_Int(1);
    return Item;
}

station SetStat()
{
    station Item;
    system("cls");
    cout << "Добавление КС\n";
    cout << "Имя: ";
    getline(cin, Item.name);
    cout << "Кол-во цехов: ";
    Item.countWS = Take_Int(1000000);
    while (Item.countWS <= 0) {
        cout << "Кол-во цехов должно быть больше 0!" << endl;
        Item.countWS = Take_Int(1000000);
    }
    cout << "Кол-во цехов в работе: ";
    Item.actWS = Take_Int(1000000);
    while (Item.countWS < Item.actWS) {
        cout << "Количество цехов в работе должно быть меньше либо равно общему количеству цехов!" << endl;
        Item.actWS = Take_Int(1000000);
    }
    cout << "Эффективность (От 0 до 1): ";
    Item.eff = Take_Float(1);
    return Item;
}

void ShowPipe(const pipe& Item) {
    cout << "Имя\t" << "Длинна\t" << "Диаметр\t" << "Ремонт\t" << endl;
    cout << "================================================" << endl;
    cout << Item.name << '\t' << Item.lenght << '\t' << Item.diametr << '\t' << Item.repair << endl;
}

void ShowStat(const station& Item) {
    cout << "Имя\t" << "countWS\t" << "actWS\t" << "Эффективность\t" << endl;
    cout << "===========================================================================" << endl;
    cout << Item.name << '\t' << Item.countWS << '\t' << Item.actWS << '\t' << Item.eff << endl;
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    int pointer;

    pipe tube = { "0", 0, 0, 0 };
    station CompStation = { "0", 0, 0, 0 };

    do {
        disp_menu();
        pointer = Take_Int(7);

        switch (pointer) {
        case 1: {
            tube = SetPipe();
            break;
        }
        case 2: {
            CompStation = SetStat();
            break;
        }
        case 3: {
            system("cls");
            cout << "Просмотр всех объектов\n\n";
            ShowPipe(tube);
            cout << "\n";
            ShowStat(CompStation);
            break;
        }
        case 4: {
            break;
        }
        case 5: {
            break;
        }
        case 6: {
            break;
        }
        case 7: {
            break;
        }
        }
        if (pointer != 0) system("pause");
    } while (pointer != 0);
    return 0;
}