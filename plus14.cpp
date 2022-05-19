#include<iostream>
using namespace std;
class demo
{
private:
    int n1 , n2;
public:
    demo(){
         this->n1 = 2;
         this->n2 = 4;  	    
    }
    demo(int a  , int b){
        this->n1 = a;
        this->n2 = b;
    }
    ~demo(){

    }
    void display(){
        cout << "value 1 = "<<this->n1 << "\nvalue 2 = "<<this->n2<<endl;
    }
};


int main()
{
    demo d1;
    demo d2(10 ,20);
    d2.display();

    return 0;
}