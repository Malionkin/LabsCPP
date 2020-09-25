#include <iostream>
#include <algorithm>
using namespace std;
const int maxSize(15);       // ввожу константу на максимальный размер массива, прижелании можно поменять
int main()
{
    cout << "Vvedite kolichestvo elementov massiva, no ne bolshe " << maxSize << endl;
    int size;
    cin >> size;

    if (size > maxSize || size <= 1)
    {
        cout << "Vy vveli plohoe col-vo!!" << endl;          // если пользователь щедрый и решит ввести больше 15
        return 0;
    }

    int variant;
    cout << "Vyberite, kakim obrazom zapolnyat' massiv:\n 1 - sam zapolnu!!!\n 2 - random\n";
    cin >> variant;

    int *arr = new int[size];
    delete [] arr;


    switch (variant)                              // псевдоменюшка для выбора способа заполнения массива
    {
        default:
        {
            cout << "Alo!! Ty Che!?" << endl;
            return 0 ;
        }
        case 1:
        {
            for (int i = 0; i<size; i++)
            {
                int element;
                cout << "Vvedite element " << i+1 << endl;
                cin >> element;
                arr[i] = element;
            }
            break;
        }
        case 2:
        {
            int span;
            cout << "Zadayte granitsu intervala randomnyh chisel!!" << endl;
            cin >> span;
            for (int i = 0; i < size; i++)
            {

                arr[i] = rand()%span;
            }
            break;

        }
    }

    int number = 1;
    for (int i = 0; i < size; ++i)
    {
        cout << "element  " << number << " raven " <<arr[i] << endl;        // вывожу красиво номера элементов массива со значениями
        number++;
    }

    cout << "Teper' vypolniaem taski!" <<  endl;

    int multi;
    for (int i = 0; i < size; i++)
    {
        if (i%2 == 1)
        {
            multi = arr[i]*arr[i-2];                         // произведение четных элементов
        }
    }

cout << "Proizvedenie chetnyh elementov massiva - " << multi << endl;

    int min = 0;
    int max = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            min = i;                                           // нахожу первый нулевой элемент
            break;
        }
    }
    for (int i = size; i > 0; i--)
    {
        if (arr[i] == 0)
        {
            max = i;                                          // нахожу последний нулевой элемент
            break;
        }
    }

    int sum = 0;

    for (int i = min; i < max; i++)
    {
        sum = sum + arr[i];                                  // нахожу сумму всех элементов между крайними нулями
    }

    if (sum > 0 )
    {
        cout << sum << endl;
    }                                                           // если есть два несоседних нулевых элемента, между которыми есть что считать (элементы мужду нулями не являются нулями)
    else                                                         // то вывожу значение суммы
    {
        cout << "Net nulevih elementov ili iskomaia summa ravna 0!!"<< endl;    //если условие не выполняется, вывожу буковки
    }

for ( int o = 0; o < maxSize; o++)             // почему использую константу, чтобы обеспечить сколь нужно большое количество итераций цикла P.S. лень расписывать подробно, зачем я это сделал, если возникнут вопросы, напишу/отвечу лично
{
    for (int i = 0; i < size -1 ; i++)
    {
        if (arr[i + 1] < 0 && arr[i] >= 0)
        {
            swap(arr[i + 1], arr[i]);           // если твой элемент неотрицателен, а следующий отрицателен - то свапаю их
        }

    }
}
cout << "Lastovaya taska:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }


    return 0;
}