#include "types.h"
#include "pstat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int pid;
    struct proc_stat p;
    if (argc != 2)
    {
        printf(1, "Error takes 1 arguement");
        exit();
    }
    pid = atoi(argv[1]);
    if (getpinfo(pid, &p) == 0)
    {
        printf(1, "PID : %d \n", p.pid);
        printf(1, "Current Queue : %d \n", p.current_queue);
        printf(1, "Last Run Time : %d \n", p.last_res_time);
        printf(1, "Number of Times process ran : %d \n", p.num_run);
        printf(1, "Total Runtime : %d \n", p.runtime);
        printf(1, "Remaining time quanta in cuurent Queue : %d \n", p.ticks[p.current_queue]);
    }
    else
    {
        printf(1, "No Process Found");
    }
    exit();
}