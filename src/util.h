#ifndef UTIL_H
#define UTIL_H

#include <stdlib.h>
#include <math.h>

/**
 * Used to quickly allocate and randomize an array of doubles.
 *
 * Supplied array will be allocated with calloc and intialized
 * with random values between 0.0 and 1.0
 *
 * @param array The array being initialized.
 * @param length The length of said array to be allocated.
 *
 */
void alloc_and_randomize( double **array, size_t length ) {
    int i;

    *array = calloc( length, sizeof( double ) );
    for ( i = 0; i < length; i++ ) {
        (*array)[i] = (double)rand() / RAND_MAX;
    }
}

double dot_product( double *array1, double *array2, size_t length ) {
    size_t i;
    double output = 0.0;

    for( i = 0; i < length; i++ ) {
        output += array1[i] * array2[i];
    }

    return output;
}


#endif /* UTIL_H */
