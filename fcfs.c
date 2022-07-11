#include <stdio.h>
int main(){
    int i,n;
    
    printf("enter the number of processes");
    scanf("%d",&n);
    int bt[n],wt[n],tat[n],twt=0,ttat=0;
    for(i=0;i<n;i++){
            scanf("%d",&bt[i]);
    }
    wt[0] = 0;
    for(i=1;i<n;i++){
            wt[i] = wt[i-1]+bt[i-1];
            
    }
    for(i=0;i<n;i++)
    {
        tat[i] = wt[i] + bt[i];
        }
    for(i=0;i<n;i++){
            twt += wt[i];
    }
    for(i=0;i<n;i++){
            ttat += tat[i];
    }
    int awt = twt/n;
    int atat = ttat/n;
     printf("Average Waiting Time is %d\n",awt);
     printf("Average turn around time is %d\n",atat);
     return 0;
}
