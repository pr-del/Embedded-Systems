//pointer-variable = new data-type;
//delete pointer-variable; 

//Assignment :
// try to create student record (name,age,id)
// 1. use dynamic array concept 
//Hint : Student *s=new Student[n];
//int *ptr=new int[5];

#include<iostream>
using namespace std;

int main()
{
    int *arr[3];
    int n;
    cout <<"Enter length of the array\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];    
    }
    
    
    cout << "Enter array elements \n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
              cin >> arr[i][j] ;
    }
}
    cout << "Array elements are \n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
               cout <<arr[i][j] <<" " ;
    }
    cout <<"\n";
}
for (int i = 0; i < n; i++)
{
    delete arr[i];
}
    
    
    return 0;
}