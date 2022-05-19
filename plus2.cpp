#include<iostream>
using namespace std;

typedef struct student
{
    int id ;
    char name[20];
    void info_take(){
        printf("Enter Student id\n");
        scanf("%d",&id);
        printf("Enter Student name\n");
        scanf("%s",name);
    }
    void info_display(){
        printf("id -- %d\nName -- %s",id ,name);
    }
}STD;

int main()
{
    STD s1;
    s1.info_take();
    s1.info_display();
    return 0;
}