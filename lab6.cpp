<<<<<<< HEAD

=======
#include <iostream>
using namespace std;

class ProperFraction
{
private:
    int chislitel;
    int znamenatel;
    ProperFraction()
    {
    };




public:
    ProperFraction(ProperFraction const &fraction)
    {
       chislitel = fraction.chislitel;
        znamenatel = fraction.znamenatel;
    }

    ProperFraction(int chisl, int znam)
    {
        chislitel = chisl;
        znamenatel = znam;
    }


void Print()
{
    if (znamenatel == 0)
    {
        cout << "You can't divide by zero, sorry :(" << endl;
        abort();
    }
    if(chislitel<0 && znamenatel<0 )
    {
        chislitel = abs(chislitel);
        znamenatel = abs(znamenatel);
    }
    if(znamenatel<0 && chislitel>0 || znamenatel>0 && chislitel<0 )
    {
        cout << "You've entered the fraction -(" << abs(chislitel) << "/" << abs(znamenatel) << ")" << endl;
    }
    else
        {
    cout << "You've entered the fraction " << chislitel << "/" << znamenatel << endl;
        }

}

void SelfPrint()             // if you want to Input by your hands from the console
{
    int chislitel;
    int znamenatel;
    cout << "Input the chislitel" << endl;
    cin >> chislitel;
    cout << "Input the znamenatel" << endl;
    cin >> znamenatel;
    if (znamenatel == 0)
    {
        cout << "You can't divide by zero, sorry :(" << endl;
        abort();
    }
    cout << "You've entered the fraction " << chislitel << "/" << znamenatel << endl;
}

};




int main()
{
ProperFraction(-4,-5).Print();





return 0;
}
>>>>>>> Lab6
