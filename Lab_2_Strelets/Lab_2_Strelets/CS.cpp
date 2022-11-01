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