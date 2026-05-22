/*#include <stdio.h>
#include <stdlib.h>

struct Task {
    int id;
    int exec;
    int per;
    int rem;
    int next;
};

void rms(struct Task t[], int n, int sim) {
    int time = 0, sel = -1, prev = -1, start = 0;
    while (time < sim) {
        sel = -1;
        int minp = 9999;
        for (int i = 0; i < n; i++) {
            if (time == t[i].next) {
                t[i].rem = t[i].exec;
                t[i].next += t[i].per;
            }
        }
        for (int i = 0; i < n; i++) {
            if (t[i].rem > 0 && t[i].per < minp) {
                minp = t[i].per;
                sel = i;
            }
        }
        if (sel != -1) t[sel].rem--;
        if (sel != prev) {
            if (prev != -1) printf("Time %d-%d : Task %d\n", start, time, prev+1);
            else if (start < time) printf("Time %d-%d : Idle\n", start, time);
            start = time;
            prev = sel;
        }
        time++;
    }
    if (prev != -1) printf("Time %d-%d : Task %d\n", start, time, prev+1);
    else printf("Time %d-%d : Idle\n", start, time);
}

int main() {
    int n, sim;
    printf("Enter number of tasks: ");
    scanf("%d", &n);
    struct Task t[n];
    for (int i = 0; i < n; i++) {
        printf("Enter exec time and period for Task %d: ", i+1);
        scanf("%d %d", &t[i].exec, &t[i].per);
        t[i].id = i+1;
        t[i].rem = 0;
        t[i].next = 0;
    }
    printf("Enter simulation time: ");
    scanf("%d", &sim);
    printf("\nRate Monotonic Scheduling\n");
    rms(t, n, sim);
    return 0;
}
*/
