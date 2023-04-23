// This demo is for operator overloading 
#include<iostream>
using namespace std;

class sumC
{
private:
    int num1 , num2 ;
public:
    sumC(){

    }
    sumC(int a , int b)
    {
        this->num1 = a ;
        this->num2 = b ;
    }
    
    sumC operator+ (sumC const &obj){
        sumC res;
        res.num1 = this->num1 + obj.num1;
        res.num2 = this->num2 + obj.num2;
        return res;
    }
    void display(){
        cout << "Value 1 = "<<this->num1 <<"\nValue 2 = "<< this->num2<<endl;
    }
    ~sumC(){

    }
};

int main()
{
    sumC s1(10 , 20) , s2(10 , 20);
    sumC s3;
    s3 = s1 + s2;
    s3.display();
    return 0;
}