#include "tube.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int PIPE_FLAG = 1;

int Take_Int(const int a, const int b);
float Take_Float(const float a, const float b);

string tube::get_name() const { return(name); }
int tube::get_lenght() const { return(lenght); }
double tube::get_diameter() const { return(diameter); }
bool tube::get_repair() const { return(repair); }

void tube::set_repair() { // ?????????????? ?????
    cout << "Old repair status: " << repair << endl;;
    cout << "Enter the new repair status: ";
    repair = Take_Int(0, 1);
}

void tube::set_repair(bool new_status)
{
    repair = new_status;
}

ostream& operator<<(ostream& os, const tube& p) {
    return os << setw(16) << p.get_name() << "|" << setw(16) << p.get_lenght() << "|" << setw(16) << p.get_diameter()
        << "|" << setw(6) << p.get_repair() << "|" << endl;
}

istream& operator>>(istream& is, tube& p) {
    system("cls");
    cout << "Add pipe\n";
    cout << "Enter the pipeline's name: ";
    getline(cin, p.name);
    cout << "Enter pipeline's length (km): ";
    p.lenght = Take_Int(1, 1000000);
    cout << "Enter pipeline's diameter (cm): ";
    p.diameter = Take_Int(1, 1000000);
    cout << "Enter pipeline's status (0 - on, 1 - off): ";
    p.repair = Take_Int(0, 1);
    return is;
};

ofstream& operator<<(ofstream& ofs, const tube& p) {
    ofs << PIPE_FLAG << endl << p.get_name() << endl << p.get_lenght() << endl << p.get_diameter() << endl << p.get_repair()
        << endl << endl;
    return ofs;
};

ifstream& operator>>(ifstream& ifs, tube& p) {
    getline(ifs, p.name);
    ifs >> p.lenght;
    ifs >> p.diameter;
    ifs >> p.repair;
    return ifs;
};