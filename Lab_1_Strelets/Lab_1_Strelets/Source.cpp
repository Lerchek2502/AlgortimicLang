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

int Take_Int(int a,int b) {
    int buff;
    cin >> buff;
    while ((cin.fail()) || (buff < a) || (buff > b) || (cin.get() != '\n')) {
        cin.clear();
        cin.ignore(1000000, '\n');
        cout << "Введите корректное число: ";
        cin >> buff;
    }
    return buff;
}

float Take_Float(float a, float b) {
    float buff;
    cin >> buff;
    while ((cin.fail()) || (buff < a) || (buff > b) || (cin.get() != '\n')) {
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

void SetPipe(pipe& Item) {
    system("cls");
    cout << "Добавление трубы\n";
    cout << "Имя: ";
    getline(cin, Item.name);
    cout << "Длина (км): ";
    Item.lenght = Take_Int(1, 1000000);
    cout << "Диаметр (см): ";
    Item.diametr = Take_Int(1,1000000);
    cout << "Ремонт (0 - Нет или 1 - Да): ";
    Item.repair = Take_Int(0, 1);
}

void SetStat(station& Item)
{
    system("cls");
    cout << "Добавление КС\n";
    cout << "Имя: ";
    getline(cin, Item.name);
    cout << "Кол-во цехов: ";
    Item.countWS = Take_Int(1, 1000000);
    cout << "Кол-во цехов в работе: ";
    Item.actWS = Take_Int(0, Item.countWS);
    cout << "Эффективность (От 0 до 1): ";
    Item.eff = Take_Float(0, 1);
}

void ShowPipe(const pipe& Item) {
    cout << "Имя\t" << "Длина\t" << "Диаметр\t" << "Ремонт\t" << endl;
    cout << "================================================" << endl;
    if (Item.lenght != 0) {
        cout << Item.name << '\t' << Item.lenght << '\t' << Item.diametr << '\t' << Item.repair << endl;
    }
}

void ShowStat(const station& Item) {
    cout << "Имя\t" << "countWS\t" << "actWS\t" << "Эффективность\t" << endl;
    cout << "===========================================================================" << endl;
    if (Item.countWS != 0) {
        cout << Item.name << '\t' << Item.countWS << '\t' << Item.actWS << '\t' << Item.eff << endl;
    }
}

void EditPipe(pipe& Item)
{
    system("cls");
    if (Item.lenght != 0) {
        cout << "Текущий Ремонт: " << Item.repair << "\n";
        cout << "Ремонт (0 - Нет или 1 - Да): ";
        Item.repair = Take_Int(0, 1);
    }
    else {
        cout << "Труба отсутствует" << endl;
    }
}

void EditStat(station& Item)
{
    system("cls");
    if (Item.countWS != 0) {        
        cout << "Текущее кол-во цехов в работе: " << Item.actWS << "\n";
        cout << "Новое кол-во цехов в работе: ";
        Item.actWS = Take_Int(0, Item.countWS);
    }
    else {
        cout << "КС отсутствует" << endl;
    }
}

void Save(const pipe& Item1, const station& Item2) {    
    ofstream fout("C:\\Users\\strel\\Documents\\AlgortimicLang\\AlgortimicLang\\Lab_1_Strelets\\saveall.txt");
    if (Item1.lenght != 0) {
        fout << 0 << "\n" << Item1.name << "\n" << Item1.lenght << "\n" << Item1.diametr << "\n" << Item1.repair << endl;
    }

    if (Item2.countWS != 0) {
        fout << 1 << "\n" << Item2.name << "\n" << Item2.countWS << "\n" << Item2.actWS << "\n" << Item2.eff << endl;
    }
    fout.close();
}

void Upload(pipe& Item1, station& Item2) {
    ifstream fin("C:\\Users\\strel\\Documents\\AlgortimicLang\\AlgortimicLang\\Lab_1_Strelets\\saveall.txt");
    if (!fin.is_open()) // если файл не открыт
        cout << "Файл не может быть открыт!\n"; // сообщить об этом
    else {
        int q;
        for (int i = 0; i < 2; i++) {
            fin >> q;
            if (q == 0) {
                fin >> ws;
                std::getline(fin, Item1.name);
                fin >> Item1.lenght;
                fin >> Item1.diametr;
                fin >> Item1.repair;
            }
            else if (q == 1) {
                fin >> ws;
                std::getline(fin, Item2.name);
                fin >> Item2.countWS;
                fin >> Item2.actWS;
                fin >> Item2.eff;
            }
        }

        fin.close(); // закрываем файл  
        return;
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    int pointer;

    pipe tube = {};
    station CompStation = {};

    do {
        disp_menu();
        pointer = Take_Int(0, 7);

        switch (pointer) {
        case 1: {
            SetPipe(tube);
            break;
        }
        case 2: {
            SetStat(CompStation);
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