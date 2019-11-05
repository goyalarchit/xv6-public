#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int cpid, status, a, b;
    cpid = fork();
    if (cpid == 0)
    {
        for (a = 0; a < argc; a++)
            printf(1, "\n %s", argv[a]);
        argv[a] = 0;
        exec(argv[1], argv + 1);
        printf(1, "Exec %s failed", argv[1]);
        exit();
    }
    else
    {
        status = waitx(&a, &b);
        printf(1, "\n Waiting time= %d \n Running time= %d exitted with pid %d \n", a, b, status);
        exit();
    }
}
