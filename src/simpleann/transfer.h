#ifndef TRANSFER_H
#define TRANSFER_H

#define TRANSFER_TANH 0

typedef struct {

    double (*fn)(double);
    double (*deriv)(double);

} transfer;

void transfer_new( transfer *t, int which );

#endif /* TRANSFER_H */
