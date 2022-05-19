#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class student
{
private:
    string name ;
    int age ,id;
public:
    student();
    ~student();
    void accept(){
        fflush(stdin);
        cout << "Enter name "<<endl;
        getline(cin , this->name);
        cout << "Enter id "<<endl;
        cin >> this->id;
        cout << "Enter age "<<endl;
        cin >> this->age;
    }
    void display(){

        cout <<"name ->"<<this->name<<endl;
        cout <<"age ->"<<this->age<<endl;
        cout <<"id ->"<<this->id<<endl;
        cout <<"-----------------------\n";
    }
    
};

student::student()
{
    this->name = "prashant";
    this->age = 1;
    this->id  = 1;
}

student::~student()
{

}

int main()
{   
    int n;
    cout << "Enter number of the students in the class\n";
    cin >> n;
    student *s;
    s = new student [n];
    for (int i = 0; i < n; i++)
    {
        s[i].accept();
    }
    for (int i = 0; i < n; i++)
    {
        s[i].display();
    }
    delete []s;
    
    return 0;
}