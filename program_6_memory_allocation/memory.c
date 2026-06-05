#include <stdio.h>

void firstFit(int block[], int m, int process[], int n) {
    int alloc[n];
    for(int i = 0; i < n; i++)
        alloc[i] = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(block[j] >= process[i]) {
                alloc[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }
    printf("\nFirst Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, process[i]);

        if(alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
void bestFit(int block[], int m, int process[], int n) {
    int alloc[n];
    for(int i = 0; i < n; i++)
        alloc[i] = -1;
    for(int i = 0; i < n; i++) {
        int id = -1;
        for(int j = 0; j < m; j++) {
            if(block[j] >= process[i]) {
                if(id == -1 || block[j] < block[id])
                    id = j;
            }
        }
        if(id != -1) {
            alloc[i]=id;
            block[id]-= process[i];
        }
    }
    printf("\nBest Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, process[i]);

        if(alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
void worstFit(int block[], int m, int process[], int n)
{
    int alloc[n];
    for(int i = 0; i < n; i++)
        alloc[i] = -1;
    for(int i = 0; i < n; i++) {
        int id = -1;
        for(int j = 0; j < m; j++) {
            if(block[j] >= process[i]) {
                if(id == -1 || block[j] > block[id])
                    id=j;
            }
        }
        if(id != -1) {
            alloc[i] = id;
            block[id] -= process[i];
        }
    }
    printf("\nWorst Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, process[i]);

        if(alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
void main() {
    int m, n;
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    int blockSize[m], block1[m], block2[m], block3[m];
    printf("Enter sizes of memory blocks:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
        block1[i] = block2[i] = block3[i] = blockSize[i];
    }
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    int processSize[n];
    printf("Enter sizes of processes:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &processSize[i]);
    worstFit(block1, m, processSize, n);
    bestFit(block2, m, processSize, n);
    firstFit(block3, m, processSize, n);
}
