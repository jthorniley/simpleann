#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "util.h"
#include "simpleann.h"


void simple_net_new( simple_net *net, transfer tr, size_t num_layers, ... ) {

    size_t i, size;

    assert( num_layers > 0 );

    net->transfer_func = tr;
    net->num_layers = num_layers;
    net->layer_sizes = calloc( num_layers, sizeof( double ) );

    net->neurons = calloc( net->num_layers, sizeof(double*) );
    net->weights = calloc( net->num_layers, sizeof(double*) );
    net->biases = calloc( net->num_layers, sizeof(double*) );

    va_list layer_size;

    va_start( layer_size, num_layers );

    for ( i = 0; i < num_layers; i++ ) {

        size = va_arg( layer_size, int );

        net->layer_sizes = realloc( net->layer_sizes, sizeof( size_t ) * (i+1) );
        net->layer_sizes[i] = size;

        net->neurons[i] = calloc( size, sizeof(double) );
        if ( i == 0 ) {
            /* Weights and biases not used on input layer */
            net->weights[0] = NULL;
            net->biases[0] = NULL;
        } else {
            /* For hidden / output layers, initialise weights and biases */
            alloc_and_randomize( &(net->biases[i]), size );
            alloc_and_randomize( &(net->weights[i]), size * net->layer_sizes[i-1] );
        }
    }

    va_end( layer_size );

}

void simple_net_free( simple_net *net ) {

    size_t i;

    free( net->layer_sizes );

    for ( i = 0; i < net->num_layers; i++ ) {
        free( net->neurons[i] );
        free( net->weights[i] );
        free( net->biases[i] );
    }

    free( net->neurons );
    free( net->weights );
    free( net->biases );

}

void simple_net_update( simple_net *net, double *inputs ) {

    size_t i, j, k, layer_size, previous_layer_size;
    double *layer;

    /* Deep copy the supplied inputs into the network */
    for ( i = 0; i < net->layer_sizes[0]; i++ ) {
        net->neurons[0][i] = inputs[i];
    }

    /* Calculate the outputs for the remaining network stages */
    for ( i = 1; i < net->num_layers; i++ ) {

        layer = net->neurons[i];
        layer_size = net->layer_sizes[i];

        for ( j = 0; j < layer_size; j++ ) {
            layer[j] = dot_product( net->neurons[i-1], 
                    net->weights[i] + net->layer_sizes[i-1]*j,
                    net->layer_sizes[i-1] );

            layer[j] = net->transfer_func.fn( layer[j] );
        }
    }
}

void simple_net_print( simple_net *net ) {

    size_t i, j;

    for ( i = 0; i < net->num_layers; i++ ) {
        printf( "Layer %d:", i );
    
        for ( j = 0; j < net->layer_sizes[i]; j++ ) {
            printf( " %f", net->neurons[i][j] );
        }

        printf( "\n" );
    }
}

