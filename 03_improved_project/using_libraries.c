#include <stdio.h>
#include <stdlib.h>
#include "myMath.h"

int main(int argc, char** argv) {

    int n = 3;

    printf("Value on function : %d \n", getSquare(n));

    printf("Value on macro    : %d \n", NMAX);

    return (EXIT_SUCCESS);
}

