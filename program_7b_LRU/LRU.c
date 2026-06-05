/*#include <stdio.h>
void main() {
    int pages[50], frames[20], time[20];
    int n, f, i, j, pos;
    int pageFaults = 0, count = 0, found;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    for(i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }
    printf("\nPage\tFrames\tStatus\n");
    for(i = 0; i < n; i++) {
        found = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                count++;
                time[j] = count;
                found = 1;
                break;
            }
        }
        if(!found) {
            int min = time[0];
            pos = 0;
            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    pos = j;
                    break;
                }
                if(time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }
            count++;
            frames[pos] = pages[i];
            time[pos] = count;
            pageFaults++;
        }
        printf("%d\t", pages[i]);
        for(j = 0; j < f; j++) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\t%s\n", found ? "Hit" : "Miss");
    }
    printf("\nTotal Page Faults = %d\n", pageFaults);
}
*/
