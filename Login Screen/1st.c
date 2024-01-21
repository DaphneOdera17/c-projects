/* How to hide password with * */
#ifdef __cplusplus__
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    system("clear");
    char ch;
    char pass[20];
    char saved_pass[20];
start:
    
    printf("Enter your password : ");
    int i = 0;
    while(1)
    {
        ch = getchar();
        //Press Enter
        if(ch == '\n')
        {
            //End the String with '\0'
            pass[i] = '\0';
            break;
        }
        else
        {
            pass[i ++] = ch;
        }
        printf("*");
    }

    printf("\nYou Entered : %s\n", pass);
    
    FILE * ptr;
    ptr = fopen("password.txt", "r");
    fscanf(ptr, "%s", saved_pass);
    
    fclose(ptr);

    int k = strcmp(pass, saved_pass);

    if(k == 0)
    {
        puts("LOGIN SUCCESSFULLY");
    }
    else
    {
        puts("INCORRECT PASSWORD \t Try Again");
        goto start;
    }

    return 0;
}