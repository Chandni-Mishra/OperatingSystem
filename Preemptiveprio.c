#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
struct process_struct
{
  
  int at;
  int bt;
  int priority;
  int ct,wt,tat,rt,start_time;
};

int main()
{
    
    int n;
    printf("Enter total number of processes:- ");
    scanf("%d",&n);   
    bool is_completed[n];
    for(int i = 0;i<n;i++){
        is_completed[i] = false;
    }
    int bt_remaining[n];
    int current_time = 0;
    int completed = 0;
    struct process_struct ps[n]; 
    float sum_tat=0,sum_wt=0,sum_rt=0;
    int max_completion_time  = INT_MIN, min_arrival_time = INT_MAX;
    int i;
    int prev = 0;
    float t_idle_time = 0,first = 1;
    printf("\nEnter Process Arrival Time- \n");
    for(i=0;i<n;i++)
    {
      scanf("%d",&ps[i].at);
      if(ps[i].at < min_arrival_time){
        min_arrival_time = ps[i].at;
      }
    }
    printf("\nEnter Process Burst Time\n");
    for(i=0;i<n;i++){
        scanf("%d",&ps[i].bt);
        bt_remaining[i] = ps[i].bt;
    }
    printf("\nEnter Priority\n");
    for(i=0;i<n;i++){
        scanf("%d",&ps[i].priority);
    }
    
    while(completed!=n)
    {
        //find process with min. burst time in ready queue at current time
        int min_index = -1;
        int minimum = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(ps[i].at <= current_time && is_completed[i] == 0) {
                if(ps[i].priority < minimum) {
                    minimum = ps[i].priority;
                    min_index = i;
                }
                if(ps[i].priority == minimum) {
                    if(ps[i].at < ps[min_index].at) {
                        minimum = ps[i].priority;
                        min_index = i;
                    }
                }
            }
        }

//    printf("min Index=%d\n",min_index);
    if(min_index==-1)
    {
        current_time++;
    }
    else
    {
       if(bt_remaining[min_index] == ps[min_index].bt){
           ps[min_index].start_time = current_time;
           if(first == 1){
                t_idle_time += 0;
            }
            else{
                t_idle_time += (ps[min_index].start_time - prev);
            }
            first = 0;
       }

       bt_remaining[min_index]--;
       current_time++;
       prev = current_time;
       
       if(bt_remaining[min_index]==0)
       {
            ps[min_index].ct = current_time;
            if(ps[min_index].ct > max_completion_time){
                max_completion_time = ps[min_index].ct;
            }
            ps[min_index].tat = ps[min_index].ct - ps[min_index].at;
            ps[min_index].wt= ps[min_index].tat - ps[min_index].bt;
            ps[min_index].rt = ps[min_index].start_time - ps[min_index].at;
            
            
            sum_tat += ps[min_index].tat;
            sum_wt += ps[min_index].wt;
            sum_rt += ps[min_index].rt;
            completed++;
            is_completed[min_index]=true;
            
            // printf("Max=%d ", ps[min_index].ct);
       }
    }
  }
    printf("\n");
    printf("AT\tBT\tCT\tTAT\tWT\tRT\tST\n");
    for(int i = 0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",ps[i].at,ps[i].bt,ps[i].ct,ps[i].tat,ps[i].wt,ps[i].rt,ps[i].start_time);
    }
    printf("\n");
    printf("Average TAT = %.2f\n",sum_tat/n);
    printf("Average WT = %.2f\n",sum_wt/n);
    printf("Average RT = %.2f\n",sum_rt/n);
    float cycle_length = max_completion_time - min_arrival_time;
    printf("Length cycle = %.2f\n",cycle_length);
    float throughput = (float)n / cycle_length;
    printf("Through Put = %.2f\n",throughput);
    float cpu_util = ((cycle_length - t_idle_time) / cycle_length) * 100;
    printf("CPU UTILISATION:- %.2f\n",cpu_util);
    return 0;
}
