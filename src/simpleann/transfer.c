#include "transfer.h"

#include <math.h>
#include <assert.h>

/* Derivative of tanh */
double dtanh( double in ) {

    return 1 - pow( tanh(in), 2); 

}

void transfer_new( transfer *t, int which ) {

    switch ( which ) {

        case TRANSFER_TANH:

            t->fn = &tanh;
            t->deriv = &dtanh;
            break;
    
        default:
            /* Invalid transfer function supplied */
            assert(0);
    }

}
