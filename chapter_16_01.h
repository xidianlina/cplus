#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUMSQ(X,Y) ((X)*(X)+(Y)*(Y))
#define P(X) printf("name: "#X";value: %d;address: %p\n",X,&X);