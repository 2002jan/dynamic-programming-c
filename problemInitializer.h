#ifndef PROBLEM_INITIALIZER
#define PROBLEM_INITIALIZER

#define ProblemsFolder "problem_instances"

#include <stdio.h>
#include <stdlib.h>

int *weights;
int *values;
int probelmSize;
int capacity;

void initProblem(int n, int i)
{
    probelmSize = n;
    char path[128];

    sprintf(path, ".\\%s\\problem_%d_%d.txt", ProblemsFolder, n , i);

    FILE *input = fopen(path, "r");


    if(input == NULL){
        printf("Could not open file: %s\n", path);
        exit(1);
    }

    char buffer[128];
    weights = calloc(probelmSize, sizeof(int));
    values  = calloc(probelmSize, sizeof(int));

    fgets(buffer, 128, input);

    sscanf(buffer, "%d", &capacity);

    printf("%d\n", capacity);

    int j;

    for (j = 0; j < probelmSize; j++)
    {
        fgets(buffer, 128, input);
        sscanf(buffer, "%d %d", weights + j, values + j);
        printf("%d %d\n", weights[j], values[j]);
    }

    fclose(input);
}

void clearProblem()
{
    free(weights);
    free(values);
    capacity = 0;
    weights = 0;
}

#endif