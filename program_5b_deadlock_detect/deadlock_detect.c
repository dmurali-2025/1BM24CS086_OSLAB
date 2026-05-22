/*#include <stdio.h>
#define P 5
#define R 3

int alloc[P][R] = { {0,1,0}, {2,0,0}, {3,0,2}, {2,1,1}, {0,0,2} };
int req[P][R]   = { {0,0,0}, {2,0,2}, {0,0,0}, {1,0,0}, {0,0,2} };
int avail[R]    = {0,0,0};

void detect() {
    int finish[P] = {0}, seq[P], idx = 0;
    int work[R];
    for(int i=0;i<R;i++) work[i] = avail[i];

    int changed = 1;
    while(changed) {
        changed = 0;
        for(int i=0;i<P;i++) {
            if(!finish[i]) {
                int ok = 1;
                for(int j=0;j<R;j++) {
                    if(req[i][j] > work[j]) { ok=0; break; }
                }
                if(ok) {
                    for(int j=0;j<R;j++) work[j] += alloc[i][j];
                    finish[i] = 1;
                    seq[idx++] = i;
                    changed = 1;
                }
            }
        }
    }

    int dead = 0;
    for(int i=0;i<P;i++) {
        if(!finish[i]) {
            dead = 1;
            printf("P%d is in deadlock\n", i);
        }
    }
    if(!dead) {
        printf("No deadlock detected\nSafe sequence: ");
        for(int i=0;i<idx;i++) printf("P%d ", seq[i]);
        printf("\n");
    }
}

int main() {
    printf("Running deadlock detection...\n");
    detect();
    return 0;
}
*/
