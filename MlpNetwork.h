//MlpNetwork.h

#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Matrix.h"
#include "Digit.h"

#define MLP_SIZE 4

const MatrixDims imgDims = {28, 28};
const MatrixDims weightsDims[] = {{128, 784},
                                  {64,  128},
                                  {20,  64},
                                  {10,  20}};
const MatrixDims biasDims[] = {{128, 1},
                               {64,  1},
                               {20,  1},
                               {10,  1}};

class MlpNetwork
{
public:
    MlpNetwork(Matrix weights[], Matrix biases[]);

    Digit operator()(Matrix &input);//todo change input
private:
    Matrix *weights;
    Matrix *biases;

    Digit getMaxProb(Matrix &probs) const;
};

#endif // MLPNETWORK_H
