#include "Header.h"

using namespace std;

int main() {
    unordered_map <int, tube> mp_pipe;
    unordered_map <int, CS> mp_cs;
    do {
        disp_menu();
        int cursor = Take_Int(0, 13);

        switch (cursor) {
        case 1: { //���������� �����
            add_tube(mp_pipe);
            break;
        }

        case 2: { //�������������� �����
            //
            break;
        }

        case 3: { //�������� �����
            //
            break;
        }

        case 4: { //���������� ��
            add_CS(mp_cs);
            break;
        }

        case 5: { //�������������� ��
            //
            break;
        }

        case 6: { //�������� ��
            //
            break;
        }

        case 7: { //�������� ���� ��������
            disp_all(mp_pipe, mp_cs);
            break;
        }

        case 8: { //���������� � ����
            //
            break;
        }

        case 9: { //�������� �� �����
            //
            break;
        }

        case 10: { //����� ����� �� �����
            //
            break;
        }

        case 11: { //����� ����� �� �������
            //
            break;
        }

        case 12: { //����� �� �� �����
            //
            break;
        }

        case 13: { //����� �� �� �������� ����������������� �����
            //
            break;
        }

        case 0: { //�����
            return 0;
            break;
        }
        }
    } while (true);
    return 0;
}