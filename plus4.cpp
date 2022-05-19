#include<iostream>
using namespace std;

namespace na
{
    int num1 = 10;
    int num2 = 50;
} // namespace na
namespace nv
{
    int num1 = 20 ;
    int num2 = 21;
    namespace nc
    {
      int num1 = 30;  
      int num2 = 40;
    } 
    
} // namespace nv


int main()
{
    using namespace na;
    cout<<"value is "<<num1<<endl;
    cout<<"value is "<<num2<<endl;
    

    cout<<"value is "<<nv::num1<<endl;
    return 0;
}
// we can't define main() with in namespace