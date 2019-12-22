//MlpNetwork.h

#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Digit.h"
#include "Dense.h"

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

/**
 * MlpNetwork class.
 */
class MlpNetwork
{
public:
    /**
     * Constructs the network.
     * @param weights - array of 4 weights
     * @param biases - array of 4 biases
     */
    MlpNetwork(Matrix weights[], Matrix biases[]);

    /**
     * Applies the entire network on input.
     * @param input
     * @return Digit struct of the predicted num and prob.
     */
    Digit operator()(Matrix &input);

private:
    Matrix* weights;
    Matrix* biases;

    /**
     *
     * @param probs
     * @return object of type Digit. who has the max prob.
     */
    Digit _getMaxProb(Matrix &probs) const;
};

#endif // MLPNETWORK_H
