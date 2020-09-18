#include <iostream>
#include <cmath>

using namespace std;

long double fact(int N)        // создаю функцию факториала, лень писать цикл фор
{
    if(N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}

int main()
{
    long double slagaemoe, epsilon, e, maxpower, x, k, expanenta;

    cout<<"Vy hotute poschitat znachenie e v kakoi stepeni??"<<endl;
    cin>>x;
    cout<<"A s kakoi tochnostiy? Skolko znakov posle zapiatoi????????"<<endl;
    cin>>k;



    if (k<=1)
    {
        cout<<"Idiot! K>1!!";               //если пользователь хочет иметь точность в несколько знаков ДО запятой, то он идиот, либо проверяет код на прочность
        return 0;
    }

    epsilon = pow(0.1,k);            //
    slagaemoe = 1;                        // заряжаю епсилон, инициализирую переменные для вхождения в цикл
    e = 1;                                //



    for (maxpower = 1;abs(slagaemoe)>epsilon; ++maxpower)
    {
        slagaemoe = (pow(x,maxpower)/fact(maxpower));                //сама формула
        e += slagaemoe;
    }
    cout.precision(k+1);                                                          // ставлю округление до к+1 знаков после запятой, тк округляет математически и будет ругаться, если буду округлять до к знаков
    cout<<"Priblizhennoye znachenie e v stepeni x = "<<e<<endl;            //вывод значения


    cout.precision(k+1);                                                          // ставлю округление до к+1 знаков после запятой, тк округляет математически и будет ругаться, если буду округлять до к знаков
    cout<<"Sravnim nash otvet s funciei iz compa. Nash otvet =  "<<e<<endl;                  //вывод округленного значения по формуле
    expanenta = exp(x);                                                                     // присваиваю переменной значение exp в степени х
    cout.precision(k+1);                                                        //  см. 48 строчку
    cout<<"e iz compa  = "<<expanenta<<endl;                                               //  вывожу округленное значение по формуле из компа

    if(e = expanenta)
    {
        cout<<"uraaaaaaaaaaaaa!!!!"<<endl;

    }
    else                                                                                   // ну тут понятно
    {
        cout<<"neeeeeeeeeeet!!!"<<endl;
    }


    return 0;
}
