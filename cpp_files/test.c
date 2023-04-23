#include<stdio.h>

int main(int argc , char *argv[], char *envp[]){
    for (int i = 0; i < 30; i++)
    {
        printf("%s\n",envp[i]);
    }
    
    return 0;
}