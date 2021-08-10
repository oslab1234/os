#include<stdio.h>
struct Process
{
 int pid;
 int pri;
 int Btime;
 int Wtime;
 int Ttime;
};
void main()
{
 int n,i,j,TotalTtime=0,TotalWtime=0;
 printf("Enter the no. of processes : ");
 scanf("%d",&n);
 struct Process p[n],temp;
 printf("Enter the process id and their burst time, priority : \n");
 for(i=0;i<n;i++)
 scanf("%d%d%d",&p[i].pid,&p[i].Btime,&p[i].pri);
 for(i=0;i<n;i++)
 {
 for(j=0;j<n-i-1;j++)
 {
 if(p[j].pri>p[j+1].pri)
 {
 temp=p[j];
 p[j]=p[j+1];
 p[j+1]=temp;
 }
 }
 }
 p[0].Wtime=0;
 for(i=1;i<n;i++)
 p[i].Wtime=p[i-1].Wtime+p[i-1].Btime;
 for(i=0;i<n;i++)
 p[i].Ttime=p[i].Wtime+p[i].Btime;
printf(" process id Burst time Waiting time TurnAround time\n");
 printf(" ------- -- ----- ---- ------- ---- ---------- ----\n");
 for(i=0;i<n;i++)
 printf(" %d %d %d %d \n",p[i].pid,p[i].B
time,p[i].Wtime,p[i].Ttime);
 for(i=0;i<n;i++)
 {
 TotalTtime=TotalTtime+p[i].Ttime;
 TotalWtime=TotalWtime+p[i].Wtime;
 }
 printf("Average Waiting time : %f\n",((float)TotalWtime/n));
 printf("Average TurnAround time : %f\n",((float)TotalTtime/n));
}
