/*#include <stdio.h>

struct process {
    int pid;
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
    int type;
};

void fcfs(struct process q[], int n, int *current_time) {
    for (int i = 0; i < n; i++) {
        if (*current_time < q[i].AT) {
            *current_time = q[i].AT;
        }
        q[i].CT = *current_time + q[i].BT;
        q[i].TAT = q[i].CT - q[i].AT;
        q[i].WT = q[i].TAT - q[i].BT;
        *current_time += q[i].BT;
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];
    int sysCount = 0, userCount = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter PID, AT, BT, Type (0=System,1=User) for process %d:\n", i+1);
        scanf("%d %d %d %d", &p[i].pid, &p[i].AT, &p[i].BT, &p[i].type);
    }

    struct process systemQ[n], userQ[n];
    for (int i = 0; i < n; i++) {
        if (p[i].type == 0) {
            systemQ[sysCount++] = p[i];
        } else {
            userQ[userCount++] = p[i];
        }
    }

    int current_time = 0;
    fcfs(systemQ, sysCount, &current_time);
    fcfs(userQ, userCount, &current_time);

    printf("\nSystem Processes:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < sysCount; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               systemQ[i].pid,
               systemQ[i].AT,
               systemQ[i].BT,
               systemQ[i].CT,
               systemQ[i].TAT,
               systemQ[i].WT);
    }
    printf("\nUser Processes:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < userCount; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               userQ[i].pid,
               userQ[i].AT,
               userQ[i].BT,
               userQ[i].CT,
               userQ[i].TAT,
               userQ[i].WT);
    }

    return 0;
}
*/
