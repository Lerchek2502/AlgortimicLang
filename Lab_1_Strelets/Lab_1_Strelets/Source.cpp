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

void EditPipe(pipe& Item)
{
    system("cls");
    cout << "Что редактируем?\n" << "1. Имя\n" << "2. Длинна\n" << "3. Диаметр\n" << "4. Ремонт\n" << "0. Выход\n" << ">";
    int pointer = Take_Int(4);
    switch (pointer) {
    case 1:
        cout << "Текущее имя: " << Item.name << "\n";
        cout << "Новое имя: ";
        getline(cin, Item.name);
        break;
    case 2:
        cout << "Текущая длинна: " << Item.lenght << "\n";
        cout << "Новая длинна (км): ";
        Item.lenght = Take_Int(1000000);
        while (Item.lenght <= 0) {
            cout << "Длинна должна быть больше 0!" << endl;
            Item.lenght = Take_Int(1000000);
        }
        break;
    case 3:
        cout << "Текущий диаметр: " << Item.diametr << "\n";
        cout << "Новый диаметр (см): ";
        Item.diametr = Take_Int(1000000);
        while (Item.diametr <= 0) {
            cout << "Диаметр должен быть больше 0!" << endl;
            Item.diametr = Take_Int(1000000);
        }
        break;
    case 4:
        cout << "Текущий Ремонт: " << Item.repair << "\n";
        cout << "Ремонт (0 - Нет или 1 - Да): ";
        Item.repair = Take_Int(1);
        break;
    case 0:
        break;
    }
}

void EditStat(station& Item)
{
    system("cls");
    cout << "Что редактируем?\n" << "1. Имя\n" << "2. Кол-во цехов\n" << "3. Кол-во цехов в работе\n" << "4. Эффективность\n" << "0. Выход\n" << ">";
    int pointer = Take_Int(4);
    switch (pointer) {
    case 1:
        cout << "Текущее имя: " << Item.name << "\n";
        cout << "Новое имя: ";
        getline(cin, Item.name);
        break;
    case 2:
        cout << "Текущее кол-во цехов: " << Item.countWS << "\n";
        cout << "Новое кол-во цехов: ";
        Item.countWS = Take_Int(1000000);
        while (Item.countWS <= 0) {
            cout << "Кол-во цехов должно быть больше 0!" << endl;
            Item.countWS = Take_Int(1000000);
        }
        break;
    case 3:
        cout << "Текущее кол-во цехов в работе: " << Item.actWS << "\n";
        cout << "Новое кол-во цехов в работе: ";
        Item.actWS = Take_Int(1000000);
        while (Item.countWS < Item.actWS) {
            cout << "Количество цехов в работе должно быть меньше либо равно общему количеству цехов!" << endl;
            Item.actWS = Take_Int(1000000);
        }
        break;
    case 4:
        cout << "Текущая эффективность: " << Item.eff << "\n";
        cout << "Новая эффективность (От 0 до 1): ";
        Item.eff = Take_Float(1);
        break;
    case 0:
        break;
    }
}

void Save(const pipe& Item1, const station& Item2) {    
    ofstream fout("C:\\Users\\strel\\Documents\\AlgortimicLang\\AlgortimicLang\\Lab_1_Strelets\\saveall.txt");
    fout << Item1.name << "/" << Item1.lenght << "/" << Item1.diametr << "/" << Item1.repair << endl;
    fout << Item2.name << "/" << Item2.countWS << "/" << Item2.actWS << "/" << Item2.eff << endl;
    fout.close();
}

void Upload(pipe& Item1, station& Item2) {
    ifstream fin("C:\\Users\\strel\\Downloads\\Shipov_Lab_1\\mas.txt");
    string buff;
    if (!fin.is_open()) // если файл не открыт
        cout << "Файл не может быть открыт!\n"; // сообщить об этом
    else {
        getline(fin, Item1.name, '/');
        getline(fin, buff, '/');
        if (stoi(buff) <= 0) {
            cout << "Файл не корректен 1!" << endl;
            return;
        }
        else {
            Item1.lenght = stoi(buff);
        }
        getline(fin, buff, '/');
        if (stoi(buff) <= 0) {
            cout << "Файл не корректен 2!" << endl;
            return;
        }
        else {
            Item1.diametr = stoi(buff);
        }
        getline(fin, buff);
        if ((stoi(buff) < 0) || (stoi(buff) > 1)) {
            cout << "Файл не корректен 3!" << endl;
            return;
        }
        else {
            Item1.repair = stoi(buff);
        }

        getline(fin, Item2.name, '/');
        getline(fin, buff, '/');
        if (stoi(buff) <= 0) {
            cout << "Файл не корректен 4!" << endl;
            return;
        }
        else {
            Item2.countWS = stoi(buff);
        }
        getline(fin, buff, '/');
        if (Item2.countWS < stoi(buff)) {
            cout << "Файл не корректен 5!" << endl;
            return;
        }
        else {
            Item2.actWS = stoi(buff);
        }
        getline(fin, buff);
        if ((stof(buff) < 0) || (stof(buff) > 1)) {
            cout << "Файл не корректен 6!" << endl;
            return;
        }
        else {
            Item2.eff = stof(buff);
        }
        fin.close(); // закрываем файл  
        return;
    }
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
            EditPipe(tube);
            break;
        }
        case 5: {
            EditStat(CompStation);
            break;
        }
        case 6: {
            Save(tube, CompStation);
            break;
        }
        case 7: {
            Upload(tube, CompStation);
            break;
        }
        }
        if (pointer != 0) system("pause");
    } while (pointer != 0);
    return 0;
}