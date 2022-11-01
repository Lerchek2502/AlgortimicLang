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

    friend ostream& operator<<(ostream& os, const tube& p);
    friend istream& operator>>(istream& is, tube& p);

};