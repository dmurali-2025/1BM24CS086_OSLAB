#include <stdio.h>
int main() {
    int pages[50], frames[20];
    int n, f, i, j, k;
    int pageFaults = 0, index = 0, found;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    for(i = 0; i < f; i++)
        frames[i] = -1;
    printf("\nPage\tFrames\t\tStatus\n");
    for(i = 0; i < n; i++) {
        found = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if(!found) {
            frames[index] = pages[i];
            index = (index + 1) % f;
            pageFaults++;
        }
        printf("%d\t", pages[i]);

        for(k = 0; k < f; k++) {
            if(frames[k] != -1)
                printf("%d ", frames[k]);
            else
                printf("- ");
        }
        printf("\t%s\n", found ? "Hit" : "Miss");
    }
    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}
