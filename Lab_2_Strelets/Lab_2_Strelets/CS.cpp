#include "CS.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int CS_FLAG = 2;

int Take_Int(const int a, const int b);
float Take_Float(const float a, const float b);

string CS::get_name() const { return(name); }
int CS::get_num_ws() const { return(num_ws); }
int CS::get_on_ws() const { return(on_ws); }
double CS::get_eff() const { return(eff); }

void CS::set_on_ws() { // Редактирование КС      
    cout << "Old number active workshops: " << on_ws << endl;
    cout << "Enter new number of active worckshop: ";
    on_ws = Take_Int(0, num_ws);
}

ostream& operator<<(ostream& os, const CS& stat) {
    return os << setw(16) << stat.get_name() << "|" << setw(16) << stat.get_num_ws() << "|" << setw(16) << stat.get_on_ws()
        << "|" << setw(10) << stat.get_eff() << "|" << endl;
}

istream& operator>>(istream& is, CS& stat) {
    system("cls");
    cout << "Add CS\n";
    cout << "Enter the CS's name: ";
    getline(cin, stat.name);
    cout << "Enter number of all worckshop: ";
    stat.num_ws = Take_Int(1, 1000000);
    cout << "Enter number of active worckshop: ";
    stat.on_ws = Take_Int(0, stat.num_ws);
    cout << "Enter the CS's efficiency: ";
    stat.eff = Take_Float(0, 1);
    return is;
};

ofstream& operator<<(ofstream& ofs, const CS& stat) {
    ofs << CS_FLAG << endl << stat.get_name() << endl << stat.get_on_ws() << endl << stat.get_num_ws()
        << endl << stat.get_eff() << endl << endl;
    return ofs;
};

ifstream& operator>>(ifstream& ifs, CS& stat) {
    getline(ifs, stat.name);
    ifs >> stat.on_ws;
    ifs >> stat.num_ws;
    ifs >> stat.eff;
    return ifs;
};