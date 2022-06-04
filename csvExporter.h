#ifndef PATH_MAX
#define PATH_MAX 260
#endif

#ifndef CSV_EXPORTER
#define CSV_EXPORTER

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

char output_path[] = ".\\output";

void exportToCsvEP(int *ns, double *times[], char** js, int n, int jn, char *exerciseName);

void checkSubdirectory(char *path);

void checkSubdirectory(char *path)
{
    struct stat sb;

    if (stat(path, &sb) == -1)
    {
        mkdir(path);
    }
}

void exportToCsvEP(int *ns, double *times[], char** js, int n, int jn, char *exerciseName)
{
    checkSubdirectory(output_path);

    char *path = (char *)malloc(sizeof(char) * PATH_MAX);

    sprintf(path, "%s\\output_%s.csv", output_path, exerciseName);
    
    FILE *csv;
    
    csv = fopen(path, "w+");

    if(csv == NULL)
    {
        printf("Error while opening/creating csv file!");
        exit(1);
        free(path);
    }

    int i, j;

    fprintf(csv, "Number of elements");
    for(i = 0; i < jn; i++)
        fprintf(csv, ", Execution time for %sf", js[i]);

    fprintf(csv, "\n");

    for (i = 0; i < n; i++)
    {
        fprintf(csv, "%d", ns[i]);
        for(j = 0; j < jn; j++)
            fprintf(csv, ", %f", times[j][i]);

        fprintf(csv, "\n");
    }

    fclose(csv);
    free(path);
    
}

#endif