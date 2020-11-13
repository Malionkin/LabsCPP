
#ifndef LAB7_HEADER_H
#define LAB7_HEADER_H
#include <iostream>
using namespace std;
class Student
{
public:
    friend ostream& operator<< (ostream &out, const Student &point);
    virtual double AverageScore();
    Student(int course, int group, int NumberOfRecordBook, string name);
    Student(const Student &Name);
    void GetStudentInfo();
    int GetCourse();
    int GetGroup();
    int GetNumberOfRecordBook();
    int GetId();
    string GetName();
    void SetCourse(int course);
    void SetGroup(int group);
private:
    Student(){};
    static int count;
    int Id;
    int NumberOfRecordBook;
    string name;
    int course;
    int group;
};


class FirstSessionStudent : public Student
{
private:
    int arr[4]{0,0,0,0};
public:
    double AverageScore() override;
    void GetStudentInfo();
    FirstSessionStudent(const Student &name1): Student(name1)
    {}
    FirstSessionStudent(int course, int group, int NumberOfRecordBook, string name) : Student(course, group, NumberOfRecordBook, name)
    {}
    void ReadScores1();
    void SetScores1();
};
class SecondSessionStudent : public FirstSessionStudent
{
private:
    int arr2[5]{0,0,0,0,0};
public:
    void GetStudentInfo();
    double AverageScore() override;
    SecondSessionStudent(const FirstSessionStudent &name1): FirstSessionStudent(name1)
    {}
    SecondSessionStudent(int course, int group, int NumberOfRecordBook, string name) : FirstSessionStudent(course, group, NumberOfRecordBook, name)
    {}
    void ReadScores2();
    void SetScores2();
};
ostream& operator<< (ostream &out,  Student &st);






#endif //LAB7_HEADER_H
