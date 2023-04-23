#include<iostream>
using namespace std;

//void swap_by_reference(int n1  ,int n2);
void swap_by_reference(int &a  ,int &b){
    int temp = a ;
    a = b;
    b = temp;

}
int main()
{
    int n1 = 5 ,  n2  =15; 
    cout << "value is before swap \n n1 ->"<<n1 <<"\nn2 ->"<<n2;
    swap_by_reference(n1 , n2);
    cout << "\nvalue is after swap \n n1 ->"<<n1 <<"\nn2 ->"<<n2;
    return 0;
}

