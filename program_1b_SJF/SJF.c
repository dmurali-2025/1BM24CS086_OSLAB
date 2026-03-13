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
    int CT[n],WT[n],TAT[n];
    int mark[n];
}p;

    printf("Enter process id, arrival time and burst time of processes");
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&p.Pid[i],&p.AT[i],&p.BT[i]);
        p.mark[i]=0;
    }
    int current_time=0;
    int complete=0;
    while(complete<n){
        int min=10000;
        int id=-1;
        for(int j=0;j<n;j++){
        if(p.AT[j]<=current_time && p.mark[j]==0){
            if(min>p.BT[j]){
                min=p.BT[j];
                id=j;
            }
        }
    }

    if(id!=-1){
        p.CT[id]=current_time+p.BT[id];
        p.TAT[id]=p.CT[id]-p.AT[id];
        p.WT[id]=p.TAT[id]-p.BT[id];
        p.mark[id]=1;
        current_time=p.CT[id];
        complete++;
    }else{
    current_time++;}}
    for(int i=0;i<n;i++){
        wt_avg=wt_avg+p.WT[i];
        tat_avg=tat_avg+p.TAT[i];
    }
    wt_avg=wt_avg+0.0;
    tat_avg=tat_avg+0.0;
    wt_avg=wt_avg/n;
    tat_avg=tat_avg/n;
    printf("PID\tAT\tBT\tCT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p.Pid[i],p.AT[i],p.BT[i],p.CT[i],p.WT[i],p.TAT[i]);
    }
    printf("Averages:%f\n%f",wt_avg,tat_avg);
    return 0;
}
