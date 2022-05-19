//wapf --> classes and objects in cpp

#include<iostream>
#include<string.h>

using namespace std;

class student
{
private:
    int id;
    char name[20];
    float marks;
    
public:
    void setstudent(int id1 , char *name1 ,float marks1 );

    void studentinfo()
    {
        cout<<"Student id is "<<id<<endl;
        cout<<"Student name is "<<name<<endl;
        cout<<"Mark of student is "<<marks<<endl;
    }
};

void student :: setstudent(int id1 , char *name1 ,float marks1 )
{
    id =  id1;
    strcpy(name,name1);
    marks = marks1;
}


int main()
{
    student Prashant;
    Prashant.setstudent(1 , "Bliz" , 80);
    Prashant.studentinfo();

    return 0;
}