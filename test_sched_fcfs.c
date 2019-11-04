#include "types.h"
#include "user.h"

unsigned long randstate = 1;
unsigned int
rand()
{
    randstate = randstate * 1664525 + 1013904223;
    return randstate;
}

int main(int argc, char *argv[])
{
    int cpid, status, a, b, i, s;
    for (i = 0; i < 10; i++)
    {
        cpid = fork();
        if (cpid == 0)
        {
            printf(1, "%d \n", i);
            s = rand() % 10;
            printf(1, " Executing process with child id %d  \n", i);
            for (int j = 0; j < s; j++)
                printf(1, "\t %d", j);
            printf(1, "\n");
            exit();
        }
    }
    for (i = 0; i < 10; i++)
    {
        status = waitx(&a, &b);
        printf(1, "Waiting time= %d \n Running time= %d \n process with pid %d exitted \n", a, b, status);
    }
    exit();
}
