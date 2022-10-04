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
        cout << "������� ���������� �����: ";
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
        cout << "������� ���������� �����: ";
        cin >> buff;
    }
    return buff;
}

void disp_menu() {
    system("cls");
    cout << "1. �������� �����\n";
    cout << "2. �������� ��\n";
    cout << "3. �������� ���� ��������\n";
    cout << "4. ������������� �����\n";
    cout << "5. ������������� ��\n";
    cout << "6. ���������\n";
    cout << "7. ���������\n";
    cout << "0. �����\n";
    cout << "\n�������� �������� - ";
}

pipe SetPipe() {
    pipe Item;
    system("cls");
    cout << "���������� �����\n";
    cout << "���: ";
    getline(cin, Item.name);
    cout << "������ (��): ";
    Item.lenght = Take_Int(1000000);
    while (Item.lenght <= 0) {
        cout << "������ ������ ���� ������ 0!" << endl;
        Item.lenght = Take_Int(1000000);
    }
    cout << "������� (��): ";
    Item.diametr = Take_Int(1000000);
    while (Item.diametr <= 0) {
        cout << "������� ������ ���� ������ 0!" << endl;
        Item.diametr = Take_Int(1000000);
    }
    cout << "������ (0 - ��� ��� 1 - ��): ";
    Item.repair = Take_Int(1);
    return Item;
}

station SetStat()
{
    station Item;
    system("cls");
    cout << "���������� ��\n";
    cout << "���: ";
    getline(cin, Item.name);
    cout << "���-�� �����: ";
    Item.countWS = Take_Int(1000000);
    while (Item.countWS <= 0) {
        cout << "���-�� ����� ������ ���� ������ 0!" << endl;
        Item.countWS = Take_Int(1000000);
    }
    cout << "���-�� ����� � ������: ";
    Item.actWS = Take_Int(1000000);
    while (Item.countWS < Item.actWS) {
        cout << "���������� ����� � ������ ������ ���� ������ ���� ����� ������ ���������� �����!" << endl;
        Item.actWS = Take_Int(1000000);
    }
    cout << "������������� (�� 0 �� 1): ";
    Item.eff = Take_Float(1);
    return Item;
}

void ShowPipe(const pipe& Item) {
    cout << "���\t" << "������\t" << "�������\t" << "������\t" << endl;
    cout << "================================================" << endl;
    cout << Item.name << '\t' << Item.lenght << '\t' << Item.diametr << '\t' << Item.repair << endl;
}

void ShowStat(const station& Item) {
    cout << "���\t" << "countWS\t" << "actWS\t" << "�������������\t" << endl;
    cout << "===========================================================================" << endl;
    cout << Item.name << '\t' << Item.countWS << '\t' << Item.actWS << '\t' << Item.eff << endl;
}

void EditPipe(pipe& Item)
{
    system("cls");
    cout << "��� �����������?\n" << "1. ���\n" << "2. ������\n" << "3. �������\n" << "4. ������\n" << "0. �����\n" << ">";
    int pointer = Take_Int(4);
    switch (pointer) {
    case 1:
        cout << "������� ���: " << Item.name << "\n";
        cout << "����� ���: ";
        getline(cin, Item.name);
        break;
    case 2:
        cout << "������� ������: " << Item.lenght << "\n";
        cout << "����� ������ (��): ";
        Item.lenght = Take_Int(1000000);
        while (Item.lenght <= 0) {
            cout << "������ ������ ���� ������ 0!" << endl;
            Item.lenght = Take_Int(1000000);
        }
        break;
    case 3:
        cout << "������� �������: " << Item.diametr << "\n";
        cout << "����� ������� (��): ";
        Item.diametr = Take_Int(1000000);
        while (Item.diametr <= 0) {
            cout << "������� ������ ���� ������ 0!" << endl;
            Item.diametr = Take_Int(1000000);
        }
        break;
    case 4:
        cout << "������� ������: " << Item.repair << "\n";
        cout << "������ (0 - ��� ��� 1 - ��): ";
        Item.repair = Take_Int(1);
        break;
    case 0:
        break;
    }
}

void EditStat(station& Item)
{
    system("cls");
    cout << "��� �����������?\n" << "1. ���\n" << "2. ���-�� �����\n" << "3. ���-�� ����� � ������\n" << "4. �������������\n" << "0. �����\n" << ">";
    int pointer = Take_Int(4);
    switch (pointer) {
    case 1:
        cout << "������� ���: " << Item.name << "\n";
        cout << "����� ���: ";
        getline(cin, Item.name);
        break;
    case 2:
        cout << "������� ���-�� �����: " << Item.countWS << "\n";
        cout << "����� ���-�� �����: ";
        Item.countWS = Take_Int(1000000);
        while (Item.countWS <= 0) {
            cout << "���-�� ����� ������ ���� ������ 0!" << endl;
            Item.countWS = Take_Int(1000000);
        }
        break;
    case 3:
        cout << "������� ���-�� ����� � ������: " << Item.actWS << "\n";
        cout << "����� ���-�� ����� � ������: ";
        Item.actWS = Take_Int(1000000);
        while (Item.countWS < Item.actWS) {
            cout << "���������� ����� � ������ ������ ���� ������ ���� ����� ������ ���������� �����!" << endl;
            Item.actWS = Take_Int(1000000);
        }
        break;
    case 4:
        cout << "������� �������������: " << Item.eff << "\n";
        cout << "����� ������������� (�� 0 �� 1): ";
        Item.eff = Take_Float(1);
        break;
    case 0:
        break;
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
            cout << "�������� ���� ��������\n\n";
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