#include <iostream>
#include "header.h"
#include "gtest/gtest.h"
//#include "student.cpp"
using namespace std;
int Student :: count = 0;

TEST(StudentTest, GetTest)
{
Student Yakov(1,4,2023125,"Yakov");
EXPECT_EQ(Yakov.GetCourse(),1)<< "Wow! IDK it's possible" <<endl;
}
TEST(StudentTest, GetTest1)
{
Student Yakov(1,4,2023125,"Yakov");
EXPECT_EQ(Yakov.GetGroup(),4);
}
TEST(StudentTest, GetTest2)
{
Student Yakov(1,4,2023125,"Yakov");
EXPECT_EQ(Yakov.GetNumberOfRecordBook(),2023125);
}
TEST(StudentTest, SetTest)
{
Student Yakov(1,4,2023125,"Yakov");
Yakov.SetGroup(5);
EXPECT_EQ(Yakov.GetGroup(),5);
}
TEST(StudentTest, SetTest1)
{
Student Yakov(1,4,2023125,"Yakov");
Yakov.SetCourse(2);
EXPECT_EQ(Yakov.GetCourse(),2);
}
TEST(FirstSessionStudentTest, InitTest)
{
Student Yakov(1,4,2023125,"Yakov");
FirstSessionStudent Yakov_2_course(Yakov);
EXPECT_EQ(Yakov.GetCourse(),Yakov_2_course.GetCourse());
EXPECT_EQ(Yakov.GetGroup(),Yakov_2_course.GetGroup());
EXPECT_EQ(Yakov.GetName(),Yakov_2_course.GetName());
}
TEST(FirstSessionStudentTest, InitTest2)
{
FirstSessionStudent Yakov_2_course(1,4,2023125,"Yakov");
EXPECT_EQ(Yakov_2_course.GetCourse(),1);
EXPECT_EQ(Yakov_2_course.GetGroup(),4);
EXPECT_EQ(Yakov_2_course.GetNumberOfRecordBook(),2023125);
}

TEST(FirstSessionStudentTest, GetTest)
{
FirstSessionStudent Yakov(1,4,2023125,"Yakov");
EXPECT_EQ(Yakov.GetCourse(),1)<< "Wow! IDK it's possible" <<endl;
}
TEST(FirstSessionStudentTest, GetTest1)
{
FirstSessionStudent Yakov(1,4,2023125,"Yakov");
EXPECT_EQ(Yakov.GetGroup(),4);
}
TEST(FirstSessionStudentTest, GetTest2)
{
FirstSessionStudent Yakov(1,4,2023125,"Yakov");
EXPECT_EQ(Yakov.GetNumberOfRecordBook(),2023125);
}
TEST(FirstSessionStudentTest, SetTest)
{
FirstSessionStudent Yakov(1,4,2023125,"Yakov");
Yakov.SetGroup(5);
EXPECT_EQ(Yakov.GetGroup(),5);
}
TEST(FirstSessionStudentTest, SetTest1) {
FirstSessionStudent Yakov(1, 4, 2023125, "Yakov");
Yakov.SetCourse(2);
EXPECT_EQ(Yakov.GetCourse(), 2);
}

TEST(FirstSessionStudentTest, GetTestFor2init)
{
Student Yakov1(1,4,2023125,"Yakov");
FirstSessionStudent Yakov(Yakov1);
EXPECT_EQ(Yakov.GetCourse(),1)<< "Wow! IDK it's possible" <<endl;
}
TEST(FirstSessionStudentTest, GetTest1For2init)
{
Student Yakov1(1,4,2023125,"Yakov");
FirstSessionStudent Yakov(Yakov1);    EXPECT_EQ(Yakov.GetGroup(),4);
}
TEST(FirstSessionStudentTest, GetTest2For2init)
{
Student Yakov1(1,4,2023125,"Yakov");
FirstSessionStudent Yakov(Yakov1);    EXPECT_EQ(Yakov.GetNumberOfRecordBook(),2023125);
}
TEST(FirstSessionStudentTest, SetTestFor2init)
{
Student Yakov1(1,4,2023125,"Yakov");
FirstSessionStudent Yakov(Yakov1);    Yakov.SetGroup(5);
EXPECT_EQ(Yakov.GetGroup(),5);
}
TEST(FirstSessionStudentTest, SetTest1For2init) {
Student Yakov1(1,4,2023125,"Yakov");
FirstSessionStudent Yakov(Yakov1);    Yakov.SetCourse(2);
EXPECT_EQ(Yakov.GetCourse(), 2);
}
TEST(SecondSessionStudentTest, InitTest)
{
Student Yakov(1,4,2023125,"Yakov");
SecondSessionStudent Yakov_3_course(Yakov);
EXPECT_EQ(Yakov.GetCourse(),Yakov_3_course.GetCourse());
EXPECT_EQ(Yakov.GetGroup(),Yakov_3_course.GetGroup());
EXPECT_EQ(Yakov.GetName(),Yakov_3_course.GetName());
}
TEST(SecondSessionStudentTest, InitTest2)
{
SecondSessionStudent Yakov_3_course(1,4,2023125,"Yakov");
EXPECT_EQ(Yakov_3_course.GetCourse(),1);
EXPECT_EQ(Yakov_3_course.GetGroup(),4);
EXPECT_EQ(Yakov_3_course.GetNumberOfRecordBook(),2023125);
}

TEST(SecondSessionStudentTest, GetTest)
{
SecondSessionStudent Yakov(1,4,2023125,"Yakov");
EXPECT_EQ(Yakov.GetCourse(),1)<< "Wow! IDK it's possible" <<endl;
}
TEST(SecondSessionStudentTest, GetTest1)
{
SecondSessionStudent Yakov(1,4,2023125,"Yakov");
EXPECT_EQ(Yakov.GetGroup(),4);
}
TEST(SecondSessionStudentTest, GetTest2)
{
SecondSessionStudent Yakov(1,4,2023125,"Yakov");
EXPECT_EQ(Yakov.GetNumberOfRecordBook(),2023125);
}
TEST(SecondSessionStudentTest, SetTest)
{
SecondSessionStudent Yakov(1,4,2023125,"Yakov");
Yakov.SetGroup(5);
EXPECT_EQ(Yakov.GetGroup(),5);
}
TEST(SecondSessionStudentTest, SetTest1) {
SecondSessionStudent Yakov(1, 4, 2023125, "Yakov");
Yakov.SetCourse(2);
EXPECT_EQ(Yakov.GetCourse(), 2);
}


