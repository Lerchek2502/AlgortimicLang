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

//���������� �����
void add_tube(unordered_map <int, tube>& mp) {
    auto iter = mp.end();
    cin >> mp[mp.size() != 0 ? iter--, iter->first + 1 : 1];
}

//���������� ��
void add_CS(unordered_map <int, CS>& mp) {
    auto iter = mp.end();
    cin >> mp[mp.size() != 0 ? iter--, iter->first + 1 : 1];
}

//����� ���� ��������
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