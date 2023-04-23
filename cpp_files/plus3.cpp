#include<iostream>
#include<string.h>
using namespace std;

typedef struct student
{
    private:
        int id ;
        char name[20];
    public:    
        void info_take(int id1 , char *name2){
            // printf("Enter Student id\n");
            // scanf("%d",&id);
            // printf("Enter Student name\n");
            // scanf("%s",name);
            id = id1;
            strcpy(name ,name2);
        }
        void info_display(){
            printf("id -- %d\nName -- %s",id ,name);
        }
}STD;

int main()
{
    STD s1;
    s1.info_take(10 , "Prashant");
    s1.info_display();
    return 0;
}