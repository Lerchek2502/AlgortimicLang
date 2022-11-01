#pragma once
#include <string>

using namespace std;

class tube {
private:
    string name; // �������� �����
    int lenght = 0; // ����� � �� 
    int diameter = 0; // ������� ����� � ��
    bool repair = 0; // 0 �������������, 1 ��������� � �������

public:
    string get_name() const;
    int get_lenght() const;
    double get_diameter() const;
    bool get_repair() const;

    void set_repair();

    friend ostream& operator<<(ostream& os, const tube& p);
    friend istream& operator>>(istream& is, tube& p);
    friend ofstream& operator<<(ofstream& ofs, const tube& p);
    friend ifstream& operator>>(ifstream& ifs, tube& p);
};