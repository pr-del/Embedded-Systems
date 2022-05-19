#include<iostream>
using namespace std;

class student
{
private:
    int n1, n2;
public:
    student();    
    ~student();
    void display(){
        cout<<"1st value "<<n1<<"\n2nd value "<<n2;
    }
};

student::student()
{
        this->n1 = 1;
        this->n2 = 1;

}

student::~student()
{
}

int main()
{
    student s1;
    s1.display();
    return 0;
}