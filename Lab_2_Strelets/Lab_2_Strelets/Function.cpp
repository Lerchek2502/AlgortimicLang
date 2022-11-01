#include "tube.h"
#include "CS.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <unordered_map>

void disp_menu()
{
    system("cls");
    cout << "1. Add pipeline\n"
        << "2. Edit pipeline\n"
        << "3. Delete pipeline\n"
        << "4. Add compressor stations\n"
        << "5. Edit compressor stations\n"
        << "6. Delete compressor stations\n"
        << "7. Show all objects\n"
        << "8. Save\n"
        << "9. Upload\n"
        << "10. Filtration pipe by name\n"
        << "11. Filtration pipe by repair\n"
        << "12. Filtration CS by name\n"
        << "13. Filtration CS by active workshop\n"
        << "0. Exit\n"
        << "\nChoose action - ";
}

int Take_Int(const int a, const int b) {
    int n;
    std::cin >> n;
    while ((cin.fail()) || (n < a) || (n > b) || (cin.get() != '\n')) {
        std::cin.clear();
        std::cin.ignore(1000000, '\n');
        std::cout << "Enter correct number: ";
        std::cin >> n;
    }
    return n;
}

float Take_Float(const float a, const float b) {
    float n;
    std::cin >> n;
    while ((std::cin.fail()) || (n < a) || (n > b) || (std::cin.get() != '\n')) {
        std::cin.clear();
        std::cin.ignore(1000000, '\n');
        std::cout << "Enter correct number: ";
        std::cin >> n;
    }
    return n;
}

//Добавление трубы
void add_tube(unordered_map <int, tube>& mp) {
    auto iter = mp.end();
    cin >> mp[mp.size() != 0 ? iter--, iter->first + 1 : 1];
}

//Действие над трубой
using tube_func = void(*)(unordered_map <int, tube>& p, int id);
void edit_tube(unordered_map <int, tube>& mp, int id) {
    mp[id].set_repair();
}

void delete_tube(unordered_map <int, tube>& mp, int id) {
    mp.erase(id);
}

void effect_tube(unordered_map <int, tube>& mp, tube_func func) {
    system("cls");
    cout << left << "Edit pipe\n";
    cout << "|" << setw(4) << "ID" << "|" << setw(16) << "Name" << "|" << setw(16) << "Length" << "|" << setw(16) << "Diameter" << "|" << setw(6) << "Repair" << "|" << endl
        << "================================================================" << endl;
    if (mp.size() != 0) {
        for (auto iter : mp) cout << "|" << setw(4) << iter.first << "|" << iter.second;

        cout << "\nEnter the ID of pipeline: ";
        auto iter = mp.find(Take_Int(1, mp.size()));
        if (iter == mp.end()) cout << "\nWe cannot find this id. Try again \n" << endl;
        else {
            int i = iter->first;
            func(mp, i);
        }
    }
    else { std::cout << "Sorry, we didn't found any pipeline" << endl; system("pause"); }
}


//Добавление КС
void add_CS(unordered_map <int, CS>& mp) {
    auto iter = mp.end();
    cin >> mp[mp.size() != 0 ? iter--, iter->first + 1 : 1];
}

//Действие над КС
using CS_func = void(*)(unordered_map <int, CS>& p, int id);
void edit_cs(unordered_map <int, CS>& mp, int id) {
    mp[id].set_on_ws();
}

void delete_cs(unordered_map <int, CS>& mp, int id) {
    mp.erase(id);
}

void effect_cs(unordered_map <int, CS>& mp, CS_func func) {
    system("cls");
    cout << left << "Edit CS\n";
    cout << "|" << setw(4) << "ID" << "|" << setw(16) << "Name" << "|" << setw(16) << "Count WS" << "|" << setw(16) << "Act WS" << "|" << setw(10) << "Efficiency" << "|" << endl
        << "====================================================================" << endl;
    if (mp.size() != 0) {
        for (auto iter : mp) cout << "|" << setw(4) << iter.first << "|" << iter.second;

        cout << "\nEnter the ID of compressor station: ";
        auto iter = mp.find(Take_Int(1, mp.size()));
        if (iter == mp.end()) cout << "\nWe cannot find this id. Try again \n" << endl;
        else {
            int i = iter->first;
            func(mp, i);
        }
    }
    else { std::cout << "Sorry, we didn't found any CS" << endl; system("pause"); }
}

//Показ всех объектов
void disp_all(const unordered_map <int, tube>& mp_pipe, const unordered_map <int, CS>& mp_cs) {
    system("cls");
    cout << left << "All objects\n";
    cout << "|" << setw(4) << "ID" << "|" << setw(16) << "Name" << "|" << setw(16) << "Length" << "|" << setw(16) << "Diameter" << "|" << setw(6) << "Repair" << "|" << endl
        << "================================================================" << endl;
    if (mp_pipe.size() != 0) { for (auto iter : mp_pipe) cout << "|" << setw(4) << iter.first << "|" << iter.second; }
    else { std::cout << "Sorry, we didn't found any pipeline" << endl; }

    cout << endl;

    cout << "|" << setw(4) << "ID" << "|" << setw(16) << "Name" << "|" << setw(16) << "Count WS" << "|" << setw(16) << "Act WS" << "|" << setw(10) << "Efficiency" << "|" << endl
        << "====================================================================" << endl;
    if (mp_cs.size() != 0) { for (auto iter : mp_cs) cout << "|" << setw(4) << iter.first << "|" << iter.second; }
    else { std::cout << "Sorry, we didn't found any CS" << endl; }
    system("pause");
}