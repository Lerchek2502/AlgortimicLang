#include "Header.h"

using namespace std;

int main() {
    unordered_map <int, tube> mp_pipe;
    unordered_map <int, CS> mp_cs;
    do {
        disp_menu();
        int cursor = Take_Int(0, 13);

        switch (cursor) {
        case 1: { //Добавление трубы
            add_tube(mp_pipe);
            break;
        }

        case 2: { //Редактирование трубы
            //
            break;
        }

        case 3: { //Удаление трубы
            //
            break;
        }

        case 4: { //Добавление КС
            add_CS(mp_cs);
            break;
        }

        case 5: { //Редактирование КС
            //
            break;
        }

        case 6: { //Удаление КС
            //
            break;
        }

        case 7: { //Просмотр всех объектов
            disp_all(mp_pipe, mp_cs);
            break;
        }

        case 8: { //Сохранение в файл
            //
            break;
        }

        case 9: { //Загрузка из файла
            //
            break;
        }

        case 10: { //Поиск трубы по имени
            //
            break;
        }

        case 11: { //Поиск трубы по ремонту
            //
            break;
        }

        case 12: { //Поиск КС по имени
            //
            break;
        }

        case 13: { //Поиск КС по проценту незадействованных цехов
            //
            break;
        }

        case 0: { //Выход
            return 0;
            break;
        }
        }
    } while (true);
    return 0;
}