#include <iostream>
#include "Stack.h"
#include "gtest/gtest.h"
#include <typeinfo>
using namespace std;
TEST(MethodTest, IsEmpty_Test)
{
  Stack<int> st;
  EXPECT_EQ(st.isEmpty(),1);
}

TEST(MethodTest, Push_Test)
{
Stack<int> st;
st.Push(1);
EXPECT_EQ(st.Top(), 1);
}

TEST(MethodTest, Top_Test)
{
  Stack<int> st;
  st.Push(1);
  st.Push(2);
  EXPECT_EQ(st.Top(), 2);
}

TEST(MethodTest, Pop_Test)
{
  Stack<int> st;
  st.Push(1);
  st.Push(2);
  EXPECT_EQ(st.Pop(), 2);
}


TEST(MethodTest, Size_Test)
{
  Stack<int> st;
  st.Push(1);
  st.Push(2);
  st.Push(3);
  EXPECT_EQ(st.Size(),3);
}

TEST(OperatorTest, largerOp_Test)
{
  Stack<int> st;
  st.Push(1);
  Stack<int> st2;
  st2.Push(4);
  st2.Push(1);
  EXPECT_EQ(st2>st,1);
}

TEST(OperatorTest, lesserOp_Test)
{
  Stack<int> st;
  st.Push(1);
  Stack<int> st2;
  st2.Push(4);
  EXPECT_EQ(st2<st,0);
}

TEST(OperatorTest, equalOp_Test)
{
  Stack<int> st;
  st.Push(4);
  Stack<int> st2;
  st2.Push(4);
  EXPECT_EQ(st2==st,1);
}

TEST(OperatorTest, insert_Test)
{
  Stack<int> st;
  st.Push(4);
  Stack<int> st2;
  st2.Push(5);
  st2.Push(123123);
  st = st2;
  EXPECT_EQ(st.Top(),123123);
}

TEST(OperatorTest, pushOp_Test)
{
  Stack<int> st;
  st>>2;
  st>>123;
  EXPECT_EQ(st.Top(),123);
}

TEST(OperatorTest, returnOp_Test)
{
  Stack<int> st;
  st>>2;
  st>>123;
  EXPECT_EQ(st[0],2);
}

TEST(TemplateTest, charTest)
{
  Stack<char> st;
  EXPECT_STREQ( typeid(st).name(), "class Stack<char>");
}

TEST(TemplateTest, intTest)
{
  Stack<int> st;
  EXPECT_STREQ( typeid(st).name(), "class Stack<int>");
}

TEST(TemplateTest, doubleTest)
{
  Stack<double> st;
  EXPECT_STREQ( typeid(st).name(), "class Stack<double>");
}

TEST(TemplateTest, stringTest)
{
  Stack<string> st;
  EXPECT_STREQ( typeid(st).name(), "class Stack<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > >");
}

TEST(TemplateTest, floatTest)
{
  Stack<float> st;
  EXPECT_STREQ( typeid(st).name(), "class Stack<float>");
}
