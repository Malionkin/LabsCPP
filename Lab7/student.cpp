//
// Created by Xiaomi on 13.11.2020.
#include <iostream>
#include "header.h"
using namespace std;




     double Student:: AverageScore()
    {
        cout << "Average score is 0. No sessions." << endl;
        return 0;
    }
    Student::Student(int course, int group, int NumberOfRecordBook, char *name)
    {

        this->group = group;
        this->course = course;
        this->NumberOfRecordBook = NumberOfRecordBook;
        this->name = name;
        count++;
        Id = count;
    }


    Student::Student(const Student &Name)
    {

        this->group = Name.group;
        this->course = Name.course;
        this->NumberOfRecordBook = Name.NumberOfRecordBook;
        this->name = Name.name;
        count++;
        Id = count;
    }

    void Student:: GetStudentInfo()
    {
        cout << "Hello, i'm "<< GetName() << " - student of " <<GetCourse() << " course, " << GetGroup()<< " group, and my record book number is " << NumberOfRecordBook <<  ", with Id "<< GetId() << endl;
    }

    int Student:: GetCourse()
    {
        return course;
    }
    int Student::GetGroup()
    {
        return group;
    }
    int Student::GetNumberOfRecordBook()
    {
        return NumberOfRecordBook;
    }
    int Student::GetId()
    {
        return Id;
    }
    char* Student::GetName()
    {
        return name;
    }

    void Student::SetCourse(int course)
    {
        this->course = course;
    }
    void Student::SetGroup(int group)
    {
        this->group = group;
    }



    double FirstSessionStudent::AverageScore()
    {
        double sum =0;
        for (int i = 0; i < 4; i++)
        {
            sum += arr[i];
        }
        double av =  sum/4 ;
        cout << av << endl;
        return av;
    }
    void FirstSessionStudent::GetStudentInfo()
    {
        Student::GetStudentInfo();
        double av_test = FirstSessionStudent::AverageScore();
        cout << "My average score is " << av_test << endl;
    }

    void FirstSessionStudent::ReadScores1()
    {
        for (int i = 0; i < 4; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void FirstSessionStudent::SetScores1()
    {
        cout << "Enter you scores!" << endl;
        for (int i = 0; i < 4; i++)
        {
            cin >> arr[i];
        }
    }


    void SecondSessionStudent::GetStudentInfo()
    {
        Student::GetStudentInfo();
        double av_test2 = SecondSessionStudent::AverageScore();
        cout << "Average score during the year is " << av_test2 <<endl;
    }
    double SecondSessionStudent::AverageScore()
    {
        double sum1 =0;
        for (int i = 0; i < 5; i++)
        {
            sum1 += arr2[i];
        }

        double av2 = sum1/5;

        double av_year = (FirstSessionStudent::AverageScore()+av2)/2;
        cout << "Average score during the year is " << av_year <<endl;
        return av_year;
    }

    void SecondSessionStudent::ReadScores2()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << endl;
    }
    void SecondSessionStudent::SetScores2()
    {
        cout << "Enter you scores! And if you didn't enter your scores after first session, please use method 'Setscores1'! " << endl;
        for (int i = 0; i < 5; i++)
        {
            cin >> arr2[i];
        }
    }




ostream& operator<< (ostream &out,  Student &st)
{
    st.GetStudentInfo();
    return out;
}
