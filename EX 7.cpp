#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    int at[10], bt[10], rt[10], ct[10], tat[10], wt[10];
    int shortest;
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time of P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while (completed < n) {
        shortest = -1;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (shortest == -1 || rt[i] < rt[shortest]) {
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        rt[shortest]--;
        time++;

        if (rt[shortest] == 0) {
            completed++;
            ct[shortest] = time;
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgtat += tat[i];
        avgwt += wt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage TAT = %.2f", avgtat / n);
    printf("\nAverage WT = %.2f\n", avgwt / n);

    return 0;
}
