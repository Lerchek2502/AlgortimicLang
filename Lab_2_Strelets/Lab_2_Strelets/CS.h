#pragma once
#include <string>

using namespace std;

class CS {
private:
	string name; // Название коммпрессионой станции
	int num_ws = 0; // Количество цехов
	int on_ws = 0; // Количество цехов в работе
	float eff = 0; // Эффективность работы

public:
	string get_name() const;
	int get_num_ws() const;
	int get_on_ws() const;
	double get_eff() const;

	friend ostream& operator<<(ostream& os, const CS& stat);
	friend istream& operator>>(istream& is, CS& stat);
};
