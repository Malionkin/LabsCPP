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

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(j > i)
                cout << matrix[j][i] << "\t";
            else
                cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }


    //cout << GetMatrixElement(matrix , 1, 5);


    int negl(0);
    int *neglines = new int[negl];
bool negative = true;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i >= j)
            {
               if(matrix[i][j]<0)
               {
                   negative = true;
               }
               else
               {
                   negative = false;
                   break;
               }
            }
            else
            {
                if(GetMatrixElement(matrix,j,i)<0)
                {
                    negative = true;

                }
                else
                {
                    negative = false;
                    break;
                }
            }

        }

        if (negative == true)
        {
            neglines[negl] = i;
            negl +=1;
        }


    }


//for (int i = 0; i < negl; i++)
//{
//    cout << neglines[i] << endl;
//}


for (int i = 0; i < negl; i++)
{
    int negmax = matrix[neglines[i]][0];
    for(int j = 0; j < size; j++) {
        int el = GetMatrixElement(matrix, neglines[i], j);

        if (el > negmax) {
            negmax = el;
        }

    }
    cout << " The most positive :) element of negative elements of " << i +1 << " row is " << negmax << endl;
}

double minavg = 0;
for (int i = 0; i < size - 1; i++)
{
    int i1 = i;
    int sum1 = 0;
    for (int j = 0; j <= i; j++, i1--)
    {
        sum1 += GetMatrixElement(matrix, i1, j);
    }
    int i2 = size - i -1;
    int sum2 = 0;
    for (int j = size -1; j >=size -i -1 ; j--, i2++)
    {
        sum2 += GetMatrixElement(matrix, i2, j);
    }

    double avg1 = sum1/(i+1);
    double avg2 = sum2/(i+1);


    if (!minavg) {
        minavg = avg1;
    }

    if (avg1 < minavg)
    {
        minavg = avg1;
    }

    if (avg2 < minavg)
    {
        minavg = avg2;
    }


}

cout << " The smallest average of elements is " << minavg << endl;


    return 0;
}
