#pragma once
#include <string>

using namespace std;

class CS {
private:
	string name; // �������� �������������� �������
	int num_ws = 0; // ���������� �����
	int on_ws = 0; // ���������� ����� � ������
	float eff = 0; // ������������� ������

public:
	string get_name() const;
	int get_num_ws() const;
	int get_on_ws() const;
	double get_eff() const;

	void set_on_ws();

	friend ostream& operator<<(ostream& os, const CS& stat);
	friend istream& operator>>(istream& is, CS& stat);
	friend ofstream& operator<<(ofstream& ofs, const CS& stat);
	friend ifstream& operator>>(ifstream& ifs, CS& stat);
};
