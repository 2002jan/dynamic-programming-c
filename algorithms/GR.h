#ifndef GREEDY_KNAPSACK
#define GREEDY_KNAPSACK

#include <stdlib.h>
#include <stdio.h>

int *ws, *vs;

int compareValues(int * a, int * b)
{
    if(vs[*a] < vs[*b])
        return 1;

    if(vs[*a] > vs[*b])
        return -1;

    return 0;
}

int compareWeights(int * a, int * b)
{
    if(ws[*a] < ws[*b])
        return -1;

    if(ws[*a] > ws[*b])
        return 1;

    return 0;
}

int KnapSackValueGreedy(int W, int *weights, int *values, int n)
{
    ws = weights;
    vs = values;
    
    int *items = (int *)malloc(sizeof(int) * n);

    int i, v = 0, w = 0;

    for (i = 0; i < n; i++)
        items[i] = i;

    qsort(items, n, sizeof(int), ( int( * )( const void *, const void * ) )compareValues);

    for (i = 0; i < n; i++)
        if(w + ws[items[i]] <= W)
        {
            w += ws[items[i]];
            v += vs[items[i]];
        }

    free(items);

    return v;
}

int KnapSackWeightGreedy(int W, int *weights, int *values, int n)
{
    ws = weights;
    vs = values;
    
    int *items = (int *)malloc(sizeof(int) * n);

    int i, v = 0, w = 0;

    for (i = 0; i < n; i++)
        items[i] = i;

    qsort(items, n, sizeof(int), ( int( * )( const void *, const void * ) )compareWeights);

    for (i = 0; i < n; i++)
        if(w + ws[items[i]] <= W)
        {
            w += ws[items[i]];
            v += vs[items[i]];
        }

    free(items);

    return v;
}

#endif