#include <stdio.h>
#include <stdlib.h>

#include "problemInitializer.h"
#include "algorithms/BF.h"
#include "algorithms/DYN.h"
#include "algorithms/GR.h"

int main()
{
    initProblem(20 ,1);

    printf("%d\n", KnapSackBruteForce(capacity, weights, values, probelmSize));
    printf("%d\n", KanpSackDynamic(capacity, weights, values, probelmSize));
    printf("%d\n", KnapSackValueGreedy(capacity, weights, values, probelmSize));
    printf("%d\n", KnapSackWeightGreedy(capacity, weights, values, probelmSize));

    clearProblem();

    initProblem(20 , 2);

    printf("%d\n", KnapSackBruteForce(capacity, weights, values, probelmSize));
    printf("%d\n", KanpSackDynamic(capacity, weights, values, probelmSize));
    printf("%d\n", KnapSackValueGreedy(capacity, weights, values, probelmSize));
    printf("%d\n", KnapSackWeightGreedy(capacity, weights, values, probelmSize));

    clearProblem();

    return 0;
}