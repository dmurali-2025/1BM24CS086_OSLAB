#include <stdio.h>

struct process {
    int pid;
    int AT;
    int BT;
    int RT;
    int CT;
    int TAT;
    int WT;
};

int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter PID, AT, BT for process %d:\n", i+1);
        scanf("%d %d %d", &p[i].pid, &p[i].AT, &p[i].BT);
        p[i].RT = p[i].BT;
        p[i].CT = 0;
        p[i].TAT = 0;
        p[i].WT = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int current_time = 0;
    int completed = 0;

    while (completed < n) {
        int done_in_cycle = 0;
        for (int i = 0; i < n; i++) {
            if (p[i].RT > 0 && p[i].AT <= current_time) {
                done_in_cycle = 1;
                if (p[i].RT > tq) {
                    current_time += tq;
                    p[i].RT -= tq;
                } else {
                    current_time += p[i].RT;
                    p[i].RT = 0;
                    p[i].CT = current_time;
                    p[i].TAT = p[i].CT - p[i].AT;
                    p[i].WT = p[i].TAT - p[i].BT;
                    completed++;
                }
            }
        }
        if (!done_in_cycle) {
            current_time++;
        }
    }

    float avg_WT = 0, avg_TAT = 0;
    for (int i = 0; i < n; i++) {
        avg_WT += p[i].WT;
        avg_TAT += p[i].TAT;
    }
    avg_WT /= n;
    avg_TAT /= n;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].AT,
               p[i].BT,
               p[i].CT,
               p[i].TAT,
               p[i].WT);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_WT);
    printf("Average Turnaround Time: %.2f\n", avg_TAT);

    return 0;
}

