#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
ifstream fin;
ifstream  fin2;
fin.open("C:\\Users\\Xiaomi\\untitled22\\input1.txt");
fin2.open("C:\\Users\\Xiaomi\\untitled22\\input2.txt");
int ctr = 0;
int counter = 0;
string st,st2;
while(!fin.eof())
{
  fin>>st;                                                                                   // all this for count
  counter++;
}
  while(!fin2.eof())
  {
    fin2>>st2;
    ctr++;
  }
fin.close();
fin2.close();
int final_counter = ctr+counter;


fin.open("C:\\Users\\Xiaomi\\untitled22\\input1.txt");
fin2.open("C:\\Users\\Xiaomi\\untitled22\\input2.txt");
string *strings = new string[counter];
int i = 0;
string str1;
while(!fin.eof())
{
  fin>>str1;
  strings[i] = str1;
  i++;
}
string temp;
  for (int i = 0; i < counter - 1; i++)
{
    for (int j = 0; j < counter - i - 1; j++)
    {
      if (strings[j] > strings[j + 1])
      {
        temp = strings[j];
        strings[j] = strings[j + 1];
        strings[j + 1] = temp;
      }
    }
  }
  for (int i = 0; i < counter; i++)
  {
    if (strings[i]!=""){
    cout << strings[i] << " ";
  }}
  cout << endl;



  string *strings2 = new string[ctr];
  int i2 = 0;
  string str2;
  while(!fin2.eof())
  {
    fin2>>str2;
    strings2[i2] = str2;
    i2++;
  }


  string temp2;
  for (int i = 0; i < ctr - 1; i++)
  {
    for (int j = 0; j < ctr - i - 1; j++)
    {
      if (strings2[j] > strings2[j + 1])
      {
        temp2 = strings2[j];
        strings2[j] = strings2[j + 1];
        strings2[j + 1] = temp2;
      }
    }
  }
  for (int i = 0; i < ctr; i++)
  {
    if (strings2[i]!=""){
      cout << strings2[i] << " ";
    }}
  cout << endl;

  string *final_strings = new string[final_counter];
  for (int i = 0; i < counter; i++)
  {
    final_strings[i] = strings[i];
  }
  for(int i = 0; i < ctr; i++)
  {
    final_strings[counter+i] = strings2[i];
  }


  string temp3;
  for (int i = 0; i < final_counter - 1; i++)
  {
    for (int j = 0; j < final_counter - i - 1; j++)
    {
      if (final_strings[j] > final_strings[j + 1])
      {
        temp3 = final_strings[j];
        final_strings[j] = final_strings[j + 1];
        final_strings[j + 1] = temp3;
      }
    }
  }
  for (int i = 0; i < final_counter; i++)
  {
    if (final_strings[i]!="")
    {
      cout << final_strings[i] << " ";
    }}
  cout << endl;

  ofstream  fout;
  fout.open("C:\\Users\\Xiaomi\\untitled22\\output.txt");
for (int i = 0; i < final_counter; i++)
{
  fout<<final_strings[i]<<" ";
}





  return 0;
}
