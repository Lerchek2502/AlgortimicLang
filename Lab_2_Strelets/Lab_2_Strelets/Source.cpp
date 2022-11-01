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
            effect_tube(mp_pipe, edit_tube);
            break;
        }

        case 3: { //Удаление трубы
            effect_tube(mp_pipe, delete_tube);
            break;
        }

        case 4: { //Добавление КС
            add_CS(mp_cs);
            break;
        }

        case 5: { //Редактирование КС
            effect_cs(mp_cs, edit_cs);
            break;
        }

        case 6: { //Удаление КС
            effect_cs(mp_cs, delete_cs);
            break;
        }

        case 7: { //Просмотр всех объектов
            disp_all(mp_pipe, mp_cs);
            break;
        }

        case 8: { //Сохранение в файл
            save(mp_pipe, mp_cs);
            break;
        }

        case 9: { //Загрузка из файла
            upload(mp_pipe, mp_cs);
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