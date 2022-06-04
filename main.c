#include <stdio.h>
#include <stdlib.h>

#include "problemInitializer.h"
#include "algorithms/BF.h"

int main()
{
    initProblem(20 ,1);

    printf("%d\n", KnapSackBruteForce(capacity, weights, values, probelmSize));

    clearProblem();

    initProblem(20 , 2);

    printf("%d\n", KnapSackBruteForce(capacity, weights, values, probelmSize));

    clearProblem();

    return 0;
}