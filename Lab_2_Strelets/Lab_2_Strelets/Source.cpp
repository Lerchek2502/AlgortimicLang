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
            effect_tube(mp_pipe, edit_tube);
            break;
        }

        case 3: { //�������� �����
            effect_tube(mp_pipe, delete_tube);
            break;
        }

        case 4: { //���������� ��
            add_CS(mp_cs);
            break;
        }

        case 5: { //�������������� ��
            effect_cs(mp_cs, edit_cs);
            break;
        }

        case 6: { //�������� ��
            effect_cs(mp_cs, delete_cs);
            break;
        }

        case 7: { //�������� ���� ��������
            disp_all(mp_pipe, mp_cs);
            break;
        }

        case 8: { //���������� � ����
            save(mp_pipe, mp_cs);
            break;
        }

        case 9: { //�������� �� �����
            upload(mp_pipe, mp_cs);
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