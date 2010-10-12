#ifndef SIMPLEANN_H
#define SIMPLEANN_H

#include <stdlib.h>

#include <simpleann/transfer.h>

/**
 * Container for multilayer perceptron
 */
typedef struct {
    size_t num_layers;
    size_t *layer_sizes;

    double **neurons;
    double **weights;
    double **biases;

    transfer transfer_func;
} simple_net;


/**
 * Create a new network.
 *
 * Example, to create a network with 3 layers, 4 input neurons, 2 hidden neurons and
 * 3 output neurons, using a tanh transfer function do:
 *
 * @verbatim
 *
 * simple_net mynet;
 * transfer tr;
 * transfer_new( &tr, TANH );
 * simple_net_new( &mynet, tr, 4, 2, 3 );
 *
 * @endverbatim
 *
 * @param net Network to initialize, note that this must be already malloc'd.
 */
void simple_net_new( simple_net *net, transfer tr, size_t num_layers, ... );

/** Safely deallocate all the memory for the given network.
 *
 * Note that the network itself is not free'd, just everything within it (i.e.
 * everythinh allocated by simple_net_new),
 * it is up to the client to "free" the network since its the client that owns it.
 */
void simple_net_free( simple_net *net );

/**
 * Updates the network based on the given inputs.
 *
 * Access the output nodes of the network with simple_net->outputs.
 *
 * The supplied inputs MUST be an array of length net->num_inputs.
 *
 * @param net The network being updated.
 * @param inputs The inputs supplied to the network.
 */
void simple_net_update( simple_net *net, double *inputs );

void simple_net_print( simple_net *net );

/**
 * Return a pointer to the output neurons of this network.
 *
 * Note that this returns a pointer to elements inside the supplied
 * network. Don't free the pointer that is returned (free the network
 * itself if that is desired -- see simple_net_free )
 */
double *simple_net_get_outputs( simple_net *net );

#endif /* SIMPLEANN_H */

