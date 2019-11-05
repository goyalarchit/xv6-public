#include "types.h"
#include "user.h"

unsigned long randstate = 1;
unsigned int lfsr113_Bits(void)
{
    static unsigned int z1 = 12345, z2 = 12345, z3 = 12345, z4 = 12345;
    unsigned int b;
    b = ((z1 << 6) ^ z1) >> 13;
    z1 = ((z1 & 4294967294U) << 18) ^ b;
    b = ((z2 << 2) ^ z2) >> 27;
    z2 = ((z2 & 4294967288U) << 2) ^ b;
    b = ((z3 << 13) ^ z3) >> 21;
    z3 = ((z3 & 4294967280U) << 7) ^ b;
    b = ((z4 << 3) ^ z4) >> 12;
    z4 = ((z4 & 4294967168U) << 13) ^ b;
    return (z1 ^ z2 ^ z3 ^ z4);
}

int main(int argc, char *argv[])
{
    int cpid, status, a, b, i, s;
    for (i = 0; i < 1000; i++)
    {
        cpid = fork();
        if (cpid == 0)
        {
            printf(1, "%d \n", i);
            s = lfsr113_Bits() % 100;
            printf(1, " Executing process with child id %d ticks \n", i);
            sleep(s);
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
