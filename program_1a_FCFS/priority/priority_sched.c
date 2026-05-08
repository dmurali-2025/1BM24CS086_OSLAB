/*#include <stdio.h>

struct process {
    int PID;
    int AT;
    int BT;
    int Priority;
    int RT;
    int CT;
    int TAT;
    int WT;
    int marked;
};

int main() {
    int n, choice;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter PID, AT, Priority, BT for process %d:\n", i+1);
        scanf("%d %d %d %d", &p[i].PID, &p[i].AT, &p[i].Priority, &p[i].BT);
        p[i].RT = p[i].BT;
        p[i].marked = 0;
        p[i].CT = 0;
        p[i].TAT = 0;
        p[i].WT = 0;
    }

    printf("\nChoose Scheduling Type:\n");
    printf("1. Non-Preemptive Priority Scheduling\n");
    printf("2. Preemptive Priority Scheduling\n");
    scanf("%d", &choice);

    int current_time = 0, completed = 0;

    switch(choice) {
        case 1:
            while (completed < n) {
                int idx = -1;
                int max_priority = -1;

                for (int j = 0; j < n; j++) {
                    if (p[j].AT <= current_time && p[j].marked == 0) {
                        if (p[j].Priority > max_priority) {
                            max_priority = p[j].Priority;
                            idx = j;
                        }
                    }
                }

                if (idx != -1) {
                    p[idx].CT = current_time + p[idx].BT;
                    p[idx].TAT = p[idx].CT - p[idx].AT;
                    p[idx].WT = p[idx].TAT - p[idx].BT;
                    p[idx].marked = 1;
                    current_time = p[idx].CT;
                    completed++;
                } else {
                    current_time++;
                }
            }
            break;

        case 2:
            while (completed < n) {
                int idx = -1;
                int max_priority = -1;

                for (int j = 0; j < n; j++) {
                    if (p[j].AT <= current_time && p[j].RT > 0) {
                        if (p[j].Priority > max_priority) {
                            max_priority = p[j].Priority;
                            idx = j;
                        }
                    }
                }

                if (idx != -1) {
                    p[idx].RT--;
                    current_time++;

                    if (p[idx].RT == 0) {
                        p[idx].CT = current_time;
                        p[idx].TAT = p[idx].CT - p[idx].AT;
                        p[idx].WT = p[idx].TAT - p[idx].BT;
                        completed++;
                    }
                } else {
                    current_time++;
                }
            }
            break;

        default:
            printf("Invalid choice!\n");
            return 0;
    }

    float avg_WT = 0, avg_TAT = 0;
    for (int i = 0; i < n; i++) {
        avg_WT += p[i].WT;
        avg_TAT += p[i].TAT;
    }
    avg_WT /= n;
    avg_TAT /= n;

    printf("\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               p[i].PID,
               p[i].AT,
               p[i].BT,
               p[i].Priority,
               p[i].CT,
               p[i].TAT,
               p[i].WT);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_WT);
    printf("Average Turnaround Time: %.2f\n", avg_TAT);

    return 0;
}
*/
