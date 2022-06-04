#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "problemInitializer.h"
#include "algorithms/BF.h"
#include "algorithms/DYN.h"
#include "algorithms/GR.h"
#include "csvExporter.h"

typedef int (*findKnapSackSolution)(int, int *, int *s, int);

int main()
{
    int i, r, j, jn = 4, runs = 10, step = 20, steps = 30;

    char *algosNames[jn];
    algosNames[0] = "Brute Force";
    algosNames[1] = "Dynamic";
    algosNames[2] = "Value Greedy";
    algosNames[3] = "Weight Greedy";

    const findKnapSackSolution algos[] = {KnapSackBruteForce, KanpSackDynamic, KnapSackValueGreedy, KnapSackWeightGreedy};

    int *ns;
    double *times[jn];
    ns = (int *)calloc(steps, sizeof(int));
    for (i = 0; i < jn; i++)
        times[i] = calloc(steps, sizeof(double));
        
    printf("\nTimes:\n");


    for (i = 0; i < steps; i++)
    {
        int n = step * (i + 1);
        ns[i] = n;

        for (j = 0; j < jn; j++)
            times[j][i] = 0;

        printf("%d -> ", n);

        for (r = 1; r <= runs; r++)
        {
            initProblem(n, r);

            for (j = 0; j < jn; j++)
            {
                clock_t begin = clock();
                algos[j](capacity, weights, values, probelmSize);
                clock_t end = clock();

                times[j][i] += (double)(end - begin) / CLOCKS_PER_SEC * 1000;
            }

            clearProblem();
        }

        for (j = 0; j < jn; j++)
        {
            times[j][i] /= runs;
            printf("%fms, ", times[j][i]);
        }

        printf("\n");
    }

    exportToCsvEP(ns, times, algosNames, steps, jn, "KnapSackProblem");

    free(ns);
    for (i = 0; i < jn; i++)
        free(times[i]);

    return 0;
}