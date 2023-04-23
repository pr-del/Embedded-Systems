#include<iostream>
using namespace std;

class student {
    private: 
        int n1 , n2;
    public: 
        student(){
            this->n1 = 1;
            this->n2 = 1;
        }

        student(int a , int b){
            this->n1 = a;
            this->n2 = b;
        }
        void accept(){
            cout << "ENter n1\n";
            cin >>this->n1;

            cout << "ENter n2\n";
            cin >>this->n2;
        }
        void display(){
            cout << "value 1 ->"<<this->n1<< "\nvalue 2 ->"<<this->n2<<endl;
        }
        
};
int main()
{
  student s1[3];
  student s2[3];

   
  for (int i = 0; i < 3; i++)
  {
   s2[i]= {3 , 4};  
 }

//   for (int i = 0; i < 3; i++)
//   {
//       s1[i].accept();
      
//   }
  for (int i = 0; i < 3; i++)
  {
      
      s2[i].display();
      s1->display();
  }
  
    return 0;
}