#pragma once
#include <string>

using namespace std;

class tube {
private:
    string name; // Название трубы
    int lenght = 0; // Длина в км 
    int diameter = 0; // Диаметр трубы в см
    bool repair = 0; // 0 Функционирует, 1 Находится в ремонте

public:
    string get_name() const;
    int get_lenght() const;
    double get_diameter() const;
    bool get_repair() const;

    friend ostream& operator<<(ostream& os, const tube& p);
    friend istream& operator>>(istream& is, tube& p);

};