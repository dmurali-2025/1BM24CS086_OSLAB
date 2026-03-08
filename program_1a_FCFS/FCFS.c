#include <stdio.h>
int main(){
    int n;
    float wt_avg, tat_avg;
    printf("Enter number of processes");
    scanf("%d",&n);
    struct process{
    int Pid[n];
    int AT[n];
    int BT[n];
}p;
    int CT[n],WT[n],TAT[n];
    printf("Enter process id, arrival time and burst time of processes");
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&p.Pid[i],&p.AT[i],&p.BT[i]);
    }
    for (int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (p.AT[i]>p.AT[j]){
                int temp;
                temp= p.AT[i];
                p.AT[i]=p.AT[j];
                p.AT[j]=temp;

                temp=p.BT[i];
                p.BT[i]=p.BT[j];
                p.BT[j]=temp;

                temp= p.Pid[i];
                p.Pid[i]=p.Pid[j];
                p.Pid[j]=temp;
            }
        }
    }
    int current_time=0;
    for (int i=0;i<n;i++){
        if(current_time<p.AT[i]){
            current_time=p.AT[i];
        }
        CT[i]=current_time+p.BT[i];
        TAT[i]=CT[i]-p.AT[i];
        WT[i]=TAT[i]-p.BT[i];
        current_time=CT[i];
    }
    for(int i=0;i<n;i++){
        wt_avg=wt_avg+WT[i];
        tat_avg=tat_avg+TAT[i];
    }
    wt_avg=wt_avg+0.0;
    tat_avg=tat_avg+0.0;
    wt_avg=wt_avg/n;
    tat_avg=tat_avg/n;
    printf("PID\tAT\tBT\tCT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p.Pid[i],p.AT[i],p.BT[i],CT[i],WT[i],TAT[i]);
    }
    printf("Averages:%f\n%f",wt_avg,tat_avg);
    return 0;
}
