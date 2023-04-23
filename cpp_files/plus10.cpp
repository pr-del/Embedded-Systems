//Instance Functions -> the functions which are call with the help of objects are called as 
// Instance functions
using namespace std;
#include<iostream>


class Test
{
    private:
    int num; //local data member 
    static int s_var; // static data member 
    public:
    Test()
    {
        this->num=10;
    }
    Test(int num)
    {
        this->num=num;
    }
    ~Test()
    {

    }
    void update()
    {
        s_var+=50;
    }

    void disp()
    {
        cout<<"\n Num = "<<num<<" &num = "<<&num<<" S_Var = "<<s_var<<" &S_VAR "<<&s_var;
    }
};

 
int Test::s_var=50;

int main(void)
{
    Test t1;
    Test t2;
    Test t3;
    t1.disp();
    t2.disp();
    t3.disp();
    t1.update(); //update() is called upon t1
    t2.update();
    cout<<"\n After calling update function =";
    t1.disp(); // 10    100 
    t2.disp(); // 10    100
    t3.disp(); // 10    100


    return 0;
}