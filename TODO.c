/***INCLUDES***/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/***DEFINES***/

#define Task_Amount 2
#define Task_Len 50

/***FUNCTIONS****/

void AddTask()
{
    char Tasks[Task_Amount][Task_Len];
    static int Tasks_Counter = 0;

    if(strlen(Tasks[Tasks_Counter]) <= 0)
    {
        printf("INPUT ERROR\n");
    }
    if(Tasks_Counter > Task_Amount - 1)
    {
        printf("LIST IS FULL\n");
        return ;
    }

    printf("TASK NAME: \n");
    if(fgets (Tasks[Tasks_Counter],Task_Len ,stdin) == NULL || strlen(Tasks[Tasks_Counter]) <= 0)
    {
        printf("INPUT ERROR\n");
    }

    printf("\033[33mTASK ADDED :)\033[0m \n");

    printf("\n\033[36m$TODO LIST$\033[0m\n");

    Tasks_Counter++;
    for(int i = 0; i < Task_Amount; i++)
    {
        printf("%d. %s\n",i + 1, Tasks[i]);
    }
    char choice;

    printf("WOULD YOU LIKE TO ADD ANOTHER TASK (Y)/(N):\n");


    if(scanf("%c", &choice) != 1 || (choice != 'y' && choice != 'n' && choice != 'N' && choice !='Y'))
    {
        printf("INPUT ERROR\n");
    }

    if(choice == 'y' || choice == 'Y')
    {
        AddTask();
    }

    else if (choice == 'n' || choice == 'N')
    {
        printf("BYE BYE <(^ * ^)>\n");
        return;
    }

    return;
}

int TODO()
{
    printf("WHAT WOULD YOU LIKE TO DO TODAY?\n");
    int a;
    printf("1 - ADD A TASK\n");
    printf("2 - DELETE A TASK\n");
    printf("3 - EXIT\n");
    printf("\n");
    if(scanf("%d",&a) != 1 || a > 3 || a < 1)

    {
        printf("INPUT ERROR");
        return 1;
    }

    getchar();

    switch(a)
    {
        case(1):
            {
                AddTask();
                break;
            }
        case(2):
            printf("TASK NUMBER?\n");
            break;

        case(3):
            printf("HAVE A GREAT DAY\n");
            break;
    }

    return 0;
}

/***INIT***/

int main()
{
    printf("\n\033[36m$WELCOME TO THE TO DO LIST$ \033[0m\n");
    printf("\n");
    TODO();
    return 0;
}
