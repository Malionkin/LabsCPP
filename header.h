#ifndef LAB6_DONE_HEADER_H
#define LAB6_DONE_HEADER_H
#include <iostream>
using namespace  std;

class ProperFraction
{
private:
    ProperFraction(){};
    int chisl;
    int znam;
public:
    ProperFraction(int chislitel, int znamenatel);
    ProperFraction (const ProperFraction &value);
    int GetChisl();
    int GetZnam();
    double slozhit_s(ProperFraction &value);
    double umnozhit_na(ProperFraction &value);
    double delit_na(ProperFraction &value);
    void Print();
    int Nod();
    void Sokratit();

};
#endif //LAB6_DONE_HEADER_H
