#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

const int maxSize = 300;
char* strCat(char *strDest, const char *strSrs)
{
    int length = strlen(strDest) + strlen(strSrs);
    int len = strlen(strDest);
    for (int i = 0; i < strlen(strSrs); i++)
    {
        strDest[len+i] = strSrs[i];
    }
    strDest[length] = '\0';
    return  strDest;
}

int main()
{
    char strDest[maxSize];
    cout << "Enter the 1'st string!" << endl;
    cin >> strDest;
    char strSrs[maxSize];
    cout << "Enter the 2'nd string!" << endl;
    cin >> strSrs;
    cout << strCat(strDest, strSrs) << endl;
    cout << "1'st task is done!" << endl;




    char text[maxSize];
    vector <char> V;
    char minWord[maxSize];
    ifstream fin("xtx.txt");
    int min = maxSize;
    while(fin>>text){
    int f = 0;
    int c = 1;
    V.clear();
    V.push_back(text[0]);
    for (int i = 1; i < strlen(text) ; i++)
    {
        for (int j = 0; j < V.size();j++)
        {
            if(V[j]==text[i])
            {
              f++ ;
            }
        }
        if(f == 0)
        {
            V.push_back(text[i]);
            c++;
        }
    }

    if(c < min)
    {
        min = c;
        for ( int k = 0; k < strlen(text); k ++)
        {
          strcpy(minWord, text);
        }
    }

    }





    cout <<" 2'nd TASK IS FINALLY DONE!!!!!!!! OH MY GOD!\n " <<minWord << endl;



return 0;


}