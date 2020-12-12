#include <iostream>
using namespace std;

const int maxSize(10);

int GetMatrixElement(int **& matrix, int i, int j){
  if(i >=j )
    return matrix[i][j];
  else
    return matrix[j][i];
}

int main()
{
  cout << "Input the size of your square matrix, but it should be less then 10!!!" << endl;
  int size;
  cin >> size;
  if (size > maxSize)
  {
    cout << "Your size is more than max size!" << endl;
    return 0;
  }

  int* *matrix = new int *[size];

  cout << "In what case do you want to fulfill your matrix?\n 1 - Manual!\n 2 - Random!" << endl;
  int wayOfFulfill;
  cin >> wayOfFulfill;
  switch (wayOfFulfill)
  {
    case 1:
    {
      for (int i = 0; i < size; i++) {
        matrix[i] = new int[i + 1];
        for (int j = 0; j < i + 1; j++) {
          cout << "Please, enter the element of matrix's line!" << endl;
          cin >> matrix[i][j] ; //GetMatrixElem(ma, i, j, n)
        }
      }
      break;
    }


    case 2: {
      cout << "Enter the boarders of the span!" << endl;
      int min, max;
      cout << "From ";
      cin >> min;
      cout << " to ";
      cin >> max;
      for (int i = 0; i < size; i++) {
        matrix[i] = new int[i + 1];
        for (int j = 0; j < i + 1; j++) {
          matrix[i][j] = min + rand()%(max-min + 1);
        }
      }
      break;
    }
    default :
      cout << "Wrong case, bad boy!" << endl;
      return 0;
  }

for (int i = 0; i < size; ++i)
  {
        for (int j = 0; j < size; ++j)
  {
    cout << GetMatrixElement(matrix, i, j)<< "\t";
  }
  cout << "\t"<<endl;
}

  bool negative = false;
for (int i = 0; i < size; i++)
{
  for (int j = 0; j < size; j++)
  {
    if (GetMatrixElement(matrix,i,j)<=0)
    {
      negative = true;
    }
  }
  if (negative == true)
  {
    int max = -1000000;
    for (int k = i;k< size;k++)
    {
      if (GetMatrixElement(matrix,k,i)>=max)
      {
        max = GetMatrixElement(matrix,k,i);
      }
    }
    cout << "The biggest value of negative column is "<<max<<endl;
  }
}

  int * avg_values = new int [size*2-2];
  for (int counter = 0; counter < size-1;counter++)
  {
    int j = counter;
    int sum = 0;
    for (int i = 0; i <= counter; i ++)
    {
      sum += GetMatrixElement(matrix,i,j);
      j--;
    }
    avg_values[counter] = sum/(counter+1);
  }

  for (int counter = size-1; counter >0;counter--)
  {
    int j = counter;
    int sum = 0;
    for (int i = size - 1; j <= size -1 ; i --)
    {
      sum += GetMatrixElement(matrix,i,j);
      j++;
    }
    avg_values[(size-2) +counter] = sum/(size - counter);
  }
int min = avg_values[0];
for (int i  = 0; i < size*2 - 2; i++)
{
  if (min > avg_values[i])
  {
    min = avg_values[i];
  }
}
cout << "Minimal average value of parallels is "<<min<<endl;
  return 0;
}