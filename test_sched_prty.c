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
    int cpid, status, a, b, i, s, p;
    //char *args[] = {"wc", "ls"};
    for (i = 0; i < 5; i++)
    {
        s = rand() % 100;
        s++;
        p = rand() % 100;
        cpid = fork();
        //printf(1, "%d \n", p);
        p = set_priority(cpid, p);
        //printf(1, "%d \n", p);
        if (cpid == 0)
        {
            //printf(1, "%d \n", i);
            volatile unsigned long long i;
            for (i = 0; i < 1000000000ULL; ++i)
                ;
            //printf(1, " Going to sleep for %d  \n", s);
            //sleep(s);
            //exec(args[0], args);

            //printf(1, "Exiting \n", i);
            exit();
        }
    }
    for (i = 0; i < 5; i++)
    {
        status = waitx(&a, &b);
        status++;
        //printf(1, "Wait time= %d Run time= %d process pid %d exitted \n", a, b, status);
    }
    exit();
}
