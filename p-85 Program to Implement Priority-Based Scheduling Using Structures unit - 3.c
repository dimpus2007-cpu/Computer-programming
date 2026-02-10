#include <stdio.h>
struct Process {
    int pid;
    int burst;
    int priority;
};
int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nProcess %d Burst Time: ", i + 1);
        scanf("%d", &p[i].burst);
        printf("Process %d Priority (Lower value = Higher priority): ", i + 1);
        scanf("%d", &p[i].priority);
    }
     for(i = 0; i < n - 1; i++) {
        int min = i;
        for(j = i + 1; j < n; j++)
            if(p[j].priority < p[min].priority)
                min = j;
        if(min != i) {
            struct Process temp = p[i];
            p[i] = p[min];
            p[min] = temp;
        }
    }
    int time = 0;
    printf("\nSchedule Order:\n");
    printf("PID\tBurst\tPriority\tCompletion Time\n");
    for(i = 0; i < n; i++) {
        time += p[i].burst;
        printf("P%d\t%d\t%d\t\t%d\n", p[i].pid, p[i].burst, p[i].priority, time);
    }
    return 0;
}
