#include <stdio.h>

#define M 20

typedef struct {
    int id;
    int et;
    int dl;
    int rt;
    int at;
    int done;
} P;

int main() {
    int n;
    P p[M];
    float u = 0.0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter execution time for P%d: ", p[i].id);
        scanf("%d", &p[i].et);
        printf("Enter deadline for P%d: ", p[i].id);
        scanf("%d", &p[i].dl);

        p[i].rt = p[i].et;
        p[i].at = 0;
        p[i].done = 0;
        u += (float)p[i].et / p[i].dl;
    }

    if (u > 1.0) {
        printf("Scheduling NOT POSSIBLE\n");
        return 0;
    }

    int t = 0, cc = 0;
    while (cc < n) {
        int rq[M], rqs = 0;
        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].at <= t) {
                rq[rqs++] = i;
            }
        }
        if (rqs == 0) {
            printf("Time %d: Idle\n", t);
            t++;
            continue;
        }
        for (int i = 0; i < rqs - 1; i++) {
            for (int j = i + 1; j < rqs; j++) {
                if (p[rq[j]].dl < p[rq[i]].dl) {
                    int tmp = rq[i];
                    rq[i] = rq[j];
                    rq[j] = tmp;
                }
            }
        }
        int k = rq[0];
        printf("Time %d: P%d\n", t, p[k].id);
        p[k].rt--;
        if (p[k].rt == 0) {
            p[k].done = 1;
            cc++;
            printf("P%d finished at %d\n", p[k].id, t + 1);
        }
        t++;
    }
    return 0;
}


