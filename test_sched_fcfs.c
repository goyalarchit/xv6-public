#include "types.h"
#include "user.h"

unsigned long randstate = 999983;
unsigned int
rand()
{
    randstate = randstate * 1664525 + 1013904223;
    return randstate;
}

int main(int argc, char *argv[])
{
    int cpid, status, a, b, i, s;
    char *args[] = {"wc", "ls"};
    for (i = 0; i < 10; i++)
    {
        s = rand() % 10;
        cpid = fork();
        if (cpid == 0)
        {
            printf(1, "%d \n", i);
            for (a = 0; a < 1000; a++)
                b++;
            printf(1, " Going to sleep for %d  \n", s);
            //sleep(s);
            exec(args[0], args);

            printf(1, "\n");
        }
    }
    for (i = 0; i < 10; i++)
    {
        status = waitx(&a, &b);
        printf(1, "Wait time= %d Run time= %d process pid %d exitted \n", a, b, status);
    }
    exit();
}
