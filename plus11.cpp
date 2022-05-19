// exeption handling with try  , catch and throw functions
#include<iostream>
using namespace std;

int main()
{
    int n1 , n2 , res;
    cout << "Enter n1"<<endl;
    cin >> n1 ;
    cout << "Enter n2"<<endl;
    cin >> n2 ;
    try
    {
        if(n2 == 0){
            throw 'c';
        }
        else{
            res  = n1 / n2 ;
            cout << "Result is "<<res <<endl;
        }
    }
    // catch(int i )
    // {
    //     cerr << "Denominator should not be Zero"<< endl;
    // }
    // catch(char ch )
    // {
    //     cerr << "Denominator should not be Zero"<< endl;
    // }

    // Called as generic catch block
    // any type of values pass from catch  accepted here
    catch(...)
    {
        cerr << "Denominator should not be Zero"<< endl;
    }

    return 0;
}