#include <math.h>
#include <stdlib.h>

#include <simpleann/simpleann.h>

int main() {

    simple_net net;
    transfer tr;
    time_t tm;

    double inputs[4];
    inputs[0] = 0.0;
    inputs[1] = 1.0;
    inputs[2] = 2.0;
    inputs[3] = 3.0;

    srand( time(NULL) );

    transfer_new( &tr, TRANSFER_TANH );

    simple_net_new( &net, tr, 3, 4, 2, 2 );

    simple_net_update( &net, inputs );

    simple_net_print( &net );

    simple_net_free( &net );

}
