#ifndef BRUTE_FORCE_KNAPSACK
#define BRUTE_FORCE_KNAPSACK

#include "max.h"

int KnapSackBruteForce(int W, int *weights, int *vals, int n)
{

    if (n == 0 || W == 0)
        return 0;

    if (weights[n - 1] > W)
        return KnapSackBruteForce(W, weights, vals, n - 1);

    else
        return max(vals[n - 1] + KnapSackBruteForce(W - weights[n - 1], weights, vals, n - 1), KnapSackBruteForce(W, weights, vals, n - 1));

}

#endif