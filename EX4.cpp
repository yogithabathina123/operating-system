#include <stdio.h>
int main()
{
    int n, i, j;
    int bt[20], p[20], wt[20], tat[20];
    int temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

       for(i = 0; i <= n-1; i++)
    {
         scanf("%d", &bt[i]);
    }

       
    for(i = 0; i <= n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

            }
        }
    }

    
    wt[0] = 0;

    for(i = 0; i<=n-1; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
    }

    
    for(i = 0; i <= n-1; i++)
    {
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcess\tExecution Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i <= n-1; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               i+1, bt[i], wt[i], tat[i]);
    }
   
    return 0;
}
    
