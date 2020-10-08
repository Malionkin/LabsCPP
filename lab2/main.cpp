#include <iostream>
#include <algorithm>
using namespace std;
const int maxSize(15);       // ввожу константу на максимальный размер массива, прижелании можно поменять
int main() {
    cout << "Vvedite kolichestvo elementov massiva, no ne bolshe " << maxSize << endl;
    int size;
    cin >> size;

    if (size > maxSize || size <= 1) {
        cout << "Vy vveli plohoe col-vo!!" << endl;          // если пользователь щедрый и решит ввести больше 15
        return 0;
    }

    int variant;
    cout << "Vyberite, kakim obrazom zapolnyat' massiv:\n 1 - sam zapolnu!!!\n 2 - random\n";
    cin >> variant;

    int *arr = new int[size];
    delete[] arr;


    switch (variant)                              // псевдоменюшка для выбора способа заполнения массива
    {
        default: {
            cout << "Alo!! Ty Che!?" << endl;
            return 0;
        }
        case 1: {
            for (int i = 0; i < size; i++) {
                int element;
                cout << "Vvedite element " << i + 1 << endl;
                cin >> element;
                arr[i] = element;
            }
            break;
        }
        case 2: {
            int minrand, maxrand;
            cout << "Zadayte granitsu intervala randomnyh chisel!!" << endl;
            cout << "OT ";   cin >> minrand; cout << " DO "; cin >> maxrand; cout << endl;
            for (int i = 0; i < size; i++) {

                arr[i] = minrand + rand() % maxrand;
            }
            break;

        }
    }

    for (int i = 0; i < size; ++i) {
        cout << "element  " << i + 1 << " raven " << arr[i]
             << endl;        // вывожу красиво номера элементов массива со значениями
    }

    cout << "Teper' vypolniaem taski!" << endl;

    int multi(1);
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            multi *= arr[i];                         // произведение четных элементов
        }
    }

    cout << "Proizvedenie chetnyh elementov massiva - " << multi << endl;

    int min = 0;
    int max = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            min = i;                                           // нахожу первый нулевой элемент
            break;
        }
    }
    for (int i = size - 1; i > 0; i--) {
        if (arr[i] == 0) {
            max = i;                                          // нахожу последний нулевой элемент
            break;
        }
    }

    if (min == max) {
        cout << "There is only one null-element! Sum is 0!" << endl;
    } else {
        int sum = 0;

        for (int i = min; i < max; i++) {
            sum = sum + arr[i];                                  // нахожу сумму всех элементов между крайними нулями
        }
        cout << " Sum of elements between nulls is " << sum << endl;
    }


    for (int o = 0; o <
                    size; o++)             // почему использую константу, чтобы обеспечить сколь нужно большое количество итераций цикла P.S. лень расписывать подробно, зачем я это сделал, если возникнут вопросы, напишу/отвечу лично
    {
        for (int i = size - 1; i > 0; i--) {
            if (arr[i - 1] > 0 && arr[i] <= 0) {
                swap(arr[i - 1],
                     arr[i]);           // если твой элемент неотрицателен, а следующий отрицателен - то свапаю их
            }
        }
    }


    cout << "Lastovaya taska:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}