#include <iostream>
#include "header.h"
using namespace  std;



ProperFraction::ProperFraction(int chislitel, int znamenatel)
    {
        this->chisl = chislitel;
        this->znam = znamenatel;
        if (znamenatel == 0)
        {
            cout << "You can't devide by 0, sorry :("<<endl;
            abort();
        }
    }
ProperFraction::ProperFraction (const ProperFraction &value)
    {
        this->chisl = value.chisl;
        this->znam = value.znam;
    }
    int ProperFraction::GetChisl()
    {
        return chisl;
    }
    int ProperFraction::GetZnam()
    {
        return znam;
    }
    double ProperFraction::slozhit_s(ProperFraction &value)
    {
        this->chisl = (this->chisl*value.znam+this->znam*value.chisl);
        this->znam = this->znam*value.znam;
        return this->chisl, this->znam;
    }

    double ProperFraction::umnozhit_na(ProperFraction &value)
    {
        this->chisl = this->chisl*value.chisl;
        this->znam = this->znam*value.znam;
        return this->chisl, this->znam;
    }
    double ProperFraction::delit_na(ProperFraction &value)
    {
        this->chisl = this->chisl*value.znam;
        this->znam = this->znam*value.chisl;
        return this->chisl, this->znam;
    }
    void ProperFraction::Print()
    {
        if (znam == 0)
        {
            cout << "You can't divide by zero, sorry :(" << endl;
            abort();
        }
        if(chisl<0 && znam<0 )
        {
            chisl= abs(chisl);
            znam = abs(znam);
        }
        if(znam<0 && chisl>0 || znam>0 && chisl<0 )
        {
            cout << "The fraction is -(" << abs(chisl) << "/" << abs(znam) << ")" << endl;
        }
        else
        {
            cout << "The fraction is  " << chisl << "/" << znam << endl;
        }
    }
    int ProperFraction::Nod()
    {
        int a = abs(chisl);
        int b = abs(znam);
        int nod = 1;
        if (a > b) swap (a,b);
        for (int i=2; i < a; i++){
            if (a%i == 0 && b%i==0){
                nod = i;
            }
        }
        return nod;
    }
    void ProperFraction::Sokratit()
    {
        int nod = Nod();
        chisl /= nod;
        znam /= nod;
    }


