#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

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

int main() {
  char strDest[maxSize];
  cout << "Enter the 1'st string!" << endl;
  cin >> strDest;
  char strSrs[maxSize];
  cout << "Enter the 2'nd string!" << endl;
  cin >> strSrs;
  cout << strCat(strDest, strSrs) << endl;
  cout << "1'st task is done!" << endl;

ifstream fin;
fin.open("C:\\Users\\Xiaomi\\untitled21\\input.txt");
char ch;

int alphabet [28] = {0};
vector<char> minword;
vector<char> word;
int counter = 0;
int min_symbols = maxSize;
while(fin.get(ch))
{
  if (ch != ' ' && ch != '\n')
  {
    if(alphabet[ch - 'a'] == 0)
    {
      counter++;
    }
    alphabet[ch - 'a'] = 1;
    word.push_back(ch);
  }
  else
  {
    if(counter == 0){continue;}
    if(counter == 0){continue;}
    if(counter<min_symbols)
    {
      min_symbols = counter;
      minword = word;
    }
   for (int i = 0; i < 28; i++)
   {
     alphabet[i] = 0;
   }
   counter = 0;
   word.clear();
  }

}
  if(counter<min_symbols && counter !=0)
  {
    min_symbols = counter;
    minword = word;
  }
for (int i = 0; i < minword.size();i++)
{
  cout << minword[i];
}
cout << endl;
  return 0;
}