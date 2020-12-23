//
// Created by Xiaomi on 23.12.2020.
//

#ifndef UNTITLED25__STACK_H_
#define UNTITLED25__STACK_H_
#include <iostream>
#include <string>
#include <map>

using namespace std;
template <typename T>
class Stack
{
 private:
  T *stack;
  int top;
  int size;
  void extendDataArray()
  {
    T* newArray = new T[size * 2];
    for(int i = 0; i < size; ++i)
    {
      newArray[i] = stack[i];
    }
    delete[]stack;
    stack = newArray;
    size *= 2;
  }

 public:
  Stack()
  {
    size = 228;
    stack = new T[size];
    top = -1;
  }
  Stack(const Stack &stack_copy)
  {
    top = stack_copy.top;
    size = stack_copy.size;
    stack = new T[size];
    for (int i=0; i<=stack_copy.top; i++)
    {
      stack[i]=stack_copy.stack[i];
    }
  }
  int Size() const
  {
    return top + 1;
  }

  bool isEmpty() const
  {
    return top == -1;
  }

  void Push(const T &value)
  {
    if (top+1 == size)
    {
      extendDataArray();
    }
    cout << "Inserting " << value << endl;
    stack[++top]= value;
  }

  int Top()
  {
    if (!isEmpty())
      return stack[top];
    else
      exit(EXIT_FAILURE);
  }

  int Pop()
  {
    if (isEmpty())
    {
      cout << "StackUnderFlow - BAN!"<<endl;
      exit(EXIT_FAILURE);
    }
    int pastTop=stack[top];
    --top;
    cout << "Removing " << pastTop << endl;
    return pastTop;
  }
  bool operator== (const Stack &test)
  {
    if (test.Size()==Size())
    {
      for (int i=0; i<test.Size(); i++)
      {
        if(test.stack[i] != stack[i])
          return false;
      }
    }
    else
    {
      return false;
    }
    return true;
  }
  Stack& operator= (const Stack &stack_copy){
    if (this == &stack_copy)
    {
      return *this;
    }
    delete[] stack;
    top = stack_copy.top;
    size = stack_copy.size;
    stack = new int[stack_copy.size];
    for (int i=0; i<=stack_copy.top; i++)
    {
      stack[i]=stack_copy.stack[i];
    }
    return *this;
  }
  void operator<< (int value)
  {
    value = Pop();
  }
  void operator>> (int value)
  {
    Push(value);
  }
  int operator[] (int i)
  {
    return stack[i];
  }

  bool operator< (const Stack &a)
  {
    return Size()<a.Size();
  }

  bool operator> (const Stack &a)
  {
    return Size()>a.Size();
  }
  ~Stack()
  {
    delete [] stack;
  }
};

#endif//UNTITLED25__STACK_H_
