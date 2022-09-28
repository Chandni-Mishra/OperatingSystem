#include<stdio.h>
#include<stdlib.h>
struct process
{
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
};
int comp(const void *p,const void *q)
{
    struct process* ps0 = (struct process*)p;
    struct process* ps1 = (struct process*)q;
    if(ps0->at >= ps1->at)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int sum_tat = 0,sum_wt = 0;
    int n;
    printf("Enter total of process:");
    scanf("%d",&n);
    struct process p[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter arrival time of process %d:-",i+1);
        scanf("%d",&p[i].at);
        printf("Enter burst time of process %d:-",i+1);
        scanf("%d",&p[i].bt);
    }
    qsort(p,n,sizeof(p[0]),comp);
    p[0].ct = p[0].at+p[0].bt;
    p[0].tat = p[0].ct-p[0].at;
    p[0].wt = p[0].tat-p[0].bt;
    sum_tat += p[0].tat;
    sum_wt += p[0].wt;
    for(int i = 1;i<n;i++)
    {
        if(p[i].at >= p[i-1].ct)
        {
            p[i].ct = p[i].at + p[i].bt;
        }
        else
        {
            p[i].ct = p[i-1].ct+p[i].bt;
        }
        p[i].tat = p[i].ct-p[i].at;
        p[i].wt = p[i].tat-p[i].bt;
        p[i].rt = (p[i].ct-p[i].bt)-p[i].at;
        sum_tat += p[i].tat;
        sum_wt += p[i].wt;
    }
    printf("AT\tBT\tCT\tWT\tTAT\tRT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    }
    printf("Total turn around time is:%d\n",sum_tat);
    printf("Total waiting time is:%d\n",sum_wt);
    return 0;
}
