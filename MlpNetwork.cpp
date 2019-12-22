#include "MlpNetwork.h"

/**
 * Constructs the network.
 * @param weights - array of 4 weights
 * @param biases - array of 4 biases
 */
MlpNetwork::MlpNetwork(Matrix weights[], Matrix biases[])
{
    this->weights = weights;
    this->biases = biases;
}

/**
 * Applies the entire network on input.
 * @param input
 * @return Digit struct of the predicted num and prob.
 */
Digit MlpNetwork::operator()(Matrix &input)
{
    Activation reluctivation(Relu);
    Activation softmaxActivation(Softmax);

    Dense dense(weights[0], biases[0], Relu);
    Matrix r1 = reluctivation(dense(input));

    dense = Dense(weights[1], biases[1], Relu);
    Matrix r2 = reluctivation(dense(r1));

    dense = Dense(weights[2], biases[2], Relu);
    Matrix r3 = reluctivation(dense(r2));

    dense = Dense(weights[3], biases[3], Softmax);
    Matrix r4 = softmaxActivation(dense(r3));

    return _getMaxProb(r4);
}

/**
 *
 * @param probs
 * @return object of type Digit. who has the max prob.
 */
Digit MlpNetwork::_getMaxProb(Matrix &probs) const
{
    Digit maxDigit = {0, probs(0, 0)};
    for (unsigned int i = 1; i < 10; ++i)
    {
        if (maxDigit.probability < probs(i, 0))
        {
            maxDigit = {i, probs(i, 0)};
        }
    }
    return maxDigit;
}

