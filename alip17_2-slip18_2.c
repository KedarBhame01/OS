// Slip17_2/Slip18_2 : Write the program to simulate FCFS CPU-scheduling. The arrival time and first CPU-burst of different jobs should be input to the system. Accept no. of Processes, arrival time and burst time. The output should give Gantt chart, turnaround time and waiting time for each process. Also find the average waiting time and turnaround time

#include<stdio.h>
void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;
    int i;
    for (i = 1; i < n; i++) {

        wt[i] = bt[i - 1] + wt[i - 1];
    }
}
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    int i;
    for (i = 0; i < n; i++) tat[i] = bt[i] + wt[i];
}
void findavgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);
    printf("Processes Burst time Waiting time Turn around time\n");
    int i;
    for (i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf(" %d ", (i + 1));
        printf(" %d ", bt[i]);

        printf(" %d", wt[i]);
        printf(" %d\n", tat[i]);
    }
    int s = (float) total_wt / (float) n;
    int t = (float) total_tat / (float) n;
    printf("Average waiting time = %d", s);
    printf("\n");
    printf("Average turn around time = %d ", t);
}
int main(){
    int processes[] = {
        1,
        2,
        3
    };
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = {
        10,
        5,
        8
    };
    findavgTime(processes, n, burst_time);
    return 0;
}