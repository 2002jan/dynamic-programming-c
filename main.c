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
    int i, r, j, jn = 3, runs = 10, step = 20, steps = 30, b = 0;

    char *algosNames[jn];
    algosNames[1] = "Dynamic";
    algosNames[2] = "Value Greedy";
    algosNames[3] = "Weight Greedy";

    const findKnapSackSolution algos[] = {KanpSackDynamic, KnapSackValueGreedy, KnapSackWeightGreedy};

    int *ns;
    double *times[jn];
    long *results[jn];
    ns = (int *)calloc(steps, sizeof(int));
    for (i = 0; i < jn; i++)
    {
        times[i] = calloc(steps, sizeof(double));
        results[i] = calloc(steps, sizeof(long));
    }
    printf("\nTimes:\n");

    for (i = 0; i < steps; i++)
    {
        int n = step * (i + 1);
        ns[i] = n;

        for (j = 0; j < jn; j++)
        {
            times[j][i] = 0;
            results[j][i] = 0;
        }

        printf("%d -> ", n);

        for (r = 1; r <= runs; r++)
        {
            initProblem(n, r);

            for (j = 0; j < jn; j++)
            {
                int val;
                clock_t begin = clock();
                val = algos[j](capacity, weights, values, probelmSize);
                clock_t end = clock();

                results[j][i] += val;
                times[j][i] += (double)(end - begin) / CLOCKS_PER_SEC * 1000;
            }

            clearProblem();
        }

        for (j = 0; j < jn; j++)
        {
            results[j][i] /= runs;
            times[j][i] /= runs;
            printf("%ld => %fms, ", results[j][i], times[j][i]);
        }

        printf("\n");
    }

    exportToCsvEP(ns, times, algosNames, results, steps, jn, "KnapSackProblem");

    free(ns);
    for (i = 0; i < jn; i++)
        free(times[i]);

    return 0;
}