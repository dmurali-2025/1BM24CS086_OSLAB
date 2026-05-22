#include <stdio.h>
#define P 5
#define R 3
int alloc[P][R] = { {0,1,0}, {2,0,0}, {3,0,2}, {2,1,1}, {0,0,2} };
int max[P][R]   = { {7,5,3}, {3,2,2}, {9,0,2}, {2,2,2}, {4,3,3} };
int avail[R]    = {3,3,2};
void safety() {
    int finish[P] = {0}, safeSeq[P], idx = 0;
    int work[R];
    for(int i=0;i<R;i++) work[i] = avail[i];
    for(int k=0;k<P;k++) {
        for(int i=0;i<P;i++) {
            if(!finish[i]) {
                int ok = 1;
                for(int j=0;j<R;j++)
                    if(max[i][j]-alloc[i][j] > work[j]) { ok=0; break; }
                if(ok) {
                    for(int j=0;j<R;j++) work[j]+=alloc[i][j];
                    safeSeq[idx++] = i;
                    finish[i] = 1;
                }
            }
        }
    }
    int safe = 1;
    for(int i=0;i<P;i++) if(!finish[i]) safe=0;

    if(safe) {
        printf("Safe sequence: ");
        for(int i=0;i<P;i++) printf("P%d ", safeSeq[i]);
        printf("\n");
    } else {
        printf("System is not safe\n");
    }
}
void request(int p, int req[R]) {
    for(int i=0;i<R;i++) {
        if(req[i] > max[p][i]-alloc[p][i]) {
            printf("Error: request exceeds maximum for P%d\n", p);
            return;
        }
        if(req[i] > avail[i]) {
            printf("P%d must wait (not enough resources)\n", p);
            return;
        }
    }
    for(int i=0;i<R;i++) {
        avail[i] -= req[i];
        alloc[p][i] += req[i];
    }
    printf("After P%d request:\n", p);
    safety();
}
int main() {
    printf("Initial:\n");
    safety();

    int req[R] = {1,0,2};
    request(1, req);

    return 0;
}

