// this demo is about operator overloading

#include<iostream>
using namespace std;

class variable
{
private:
    int num1 , num2  , sum ;
public:
    variable(int &a , int &b);
    ~variable();
    void display(){
        cout <<"Sum is "<<this->sum<<endl;
    }
};

variable::variable(int &a , int &b)
{
    this->num1 = a; 
    this->num2 = b;
}

variable::~variable()
{
}

int main()
{
    
    return 0;
}