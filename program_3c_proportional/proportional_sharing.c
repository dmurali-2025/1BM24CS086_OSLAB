#include <stdio.h>

struct P {
    int id;
    int sh;
    int used;
};

int main() {
    int n, i, totSh = 0, totT;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct P p[n];
    for(i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter shares for P%d: ", i + 1);
        scanf("%d", &p[i].sh);
        p[i].used = 0;
        totSh += p[i].sh;
    }
    printf("Enter total CPU time units: ");
    scanf("%d", &totT);
    printf("CPU Scheduling Table");
    printf("\nTime Interval\tRunning Process\n");
    int cur = -1;
    int st = 0;
    for(int t = 0; t < totT; t++) {
        int sel = 0;
        float minR = (float)p[0].used / p[0].sh;
        for(i = 1; i < n; i++) {
            float r = (float)p[i].used / p[i].sh;
            if(r < minR) {
                minR = r;
                sel = i;
            }
        }
        p[sel].used++;
        if(cur == -1) {
            cur = sel;
            st = t;
        } else if(cur != sel) {
            printf("%d - %d\t\tP%d\n", st, t, p[cur].id);
            cur = sel;
            st = t;
        }
        if(t == totT - 1) {
            printf("%d - %d\t\tP%d\n", st, totT, p[cur].id);
        }
    }
    printf("\nFinal CPU Allocation");
    printf("\n\nProcess\tShares\tCPU %%\tCPU Used\n");
    for(i = 0; i < n; i++) {
        float pct = ((float)p[i].sh / totSh) * 100;
        printf("P%d\t%d\t%.2f%%\t%d\n", p[i].id, p[i].sh, pct, p[i].used);
    }
    return 0;
}

