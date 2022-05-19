#include<iostream>
using namespace std;


inline int sum(int a , int b){
    return a+b;
}
inline int sum(int a , int b ,int c){
    return a+b+c;
}
inline int sum(int a , int b , int c , int d){
    return a+b + c + d;
}

int main()
{
    
    int result ;
    result = sum(11 , 22);
    cout << "result is "<<result<<endl;
    result = sum(11 , 22 , 33);
    cout << "result is "<<result<<endl;
    result = sum(11 , 22 ,33 , 44);
    cout << "result is "<<result<<endl;

    return 0;
}