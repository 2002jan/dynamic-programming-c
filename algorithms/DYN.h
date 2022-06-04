#ifndef DYNAMIC_KNAPSACK
#define DYNAMIC_KNAPSACK

#include "max.h"
#include <stdlib.h>

int KanpSackDynamic(int W, int *weights, int *values, int n)
{
    int i, w;
    int **K;

    K = (int **)calloc(n + 1, sizeof(int *));
    for (i = 0; i < n + 1; i++)
    {
        K[i] = (int *)calloc(W + 1, sizeof(int));
    }

    for (i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if(i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    int output = K[n][W]; 

    for (i = 0; i < n + 1; i++)
    {
        free(K[i]);
    }

    free(K);

    return output;
}

#endif