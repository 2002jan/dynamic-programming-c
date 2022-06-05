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
    algosNames[0] = "Dynamic";
    algosNames[1] = "Value Greedy";
    algosNames[2] = "Weight Greedy";

    const findKnapSackSolution algos[] = {KanpSackDynamic, KnapSackValueGreedy, KnapSackWeightGreedy};

    long *results[jn];
    for (i = 0; i < jn; i++)
    {
        results[i] = calloc(steps, sizeof(long));
    }
    printf("\nTimes:\n");

    FILE * outputf = fopen(".\\output\\values.csv", "w");

    if(outputf == NULL)
    {
        printf("Error file file opening was happening");
        return 1;
    }

    fprintf(outputf, "n, r, Value for %s, Value for %s, Value for %s, Percentage for %s, Percentage for %s\n", algosNames[0], algosNames[1], algosNames[2], algosNames[1], algosNames[2]);

    for (i = 0; i < steps; i++)
    {
        int n = step * (i + 1);

        for (j = 0; j < jn; j++)
        {
            results[j][i] = 0;
        }

        for (r = 1; r <= runs; r++)
        {
            initProblem(n, r);

            for (j = 0; j < jn; j++)
            {
                results[j][i] = algos[j](capacity, weights, values, probelmSize);
            }

            clearProblem();

            printf("%d.%d %f %f\n", n, r, (double)results[1][i] / (double)results[0][i], (double)results[2][i] / (double)results[0][i]);
            fprintf(outputf, "%d, %d, %d, %d, %d, %lf, %lf\n", n, r, results[0][i], results[1][i], results[2][i], (double)results[1][i] / (double)results[0][i], (double)results[2][i] / (double)results[0][i] );
        }

        printf("\n");
    }

    fclose(outputf);

    for (i = 0; i < jn; i++)
        free(results[i]);

    return 0;
}