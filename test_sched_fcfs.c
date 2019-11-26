#include "types.h"
#include "user.h"

unsigned long randstate = 999983;
unsigned int
rand()
{
    randstate = randstate * 1664525 + 1013904223;
    return randstate;
}

int main(/*int argc, char *argv[]*/)
{
    int cpid, i;
    int p[] = {70, 40, 5, 20, 40, 8, 13, 50, 35, 90};
    for (i = 0; i < 10; i++)
    {
        cpid = fork();
        if (cpid != 0)
        {
            set_priority(cpid, p[i]);
            printf(1, "Pid = %d Priority = %d \n", cpid, p[i]);
        }
        else
        {
            volatile unsigned long long i;
            for (i = 0; i < 1000000000ULL; ++i)
                ;
            exit();
        }
    }
    for (i = 0; i < 10; i++)
    {
        wait();
    }
    exit();
}
