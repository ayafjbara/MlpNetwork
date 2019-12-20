//
// Created by Aya on 12/15/2019.
//

#include "MlpNetwork.h"

MlpNetwork::MlpNetwork(Matrix weights[], Matrix biases[]) {
    this->weights = weights;
    this->biases = biases;
}

Digit MlpNetwork::operator()(Matrix &input) {
    Activation reluctivation(Relu);
    Activation softmaxActivation(Softmax);

    Dense dense(weights[0], biases[0], Relu);
    Matrix r1 = reluctivation(dense(input));

    dense = *new Dense(weights[1], biases[1], Relu);
    Matrix r2 = reluctivation(dense(r1));

    dense = *new Dense(weights[2], biases[2], Relu);
    Matrix r3 = reluctivation(dense(r2));

    dense = *new Dense(weights[3], biases[3], Softmax);
    Matrix r4 = softmaxActivation(dense(r3));

    return getMaxProb(r4);
}

Digit MlpNetwork::getMaxProb(Matrix &probs) const {
    Digit maxDigit = {0, probs(0, 1)};
    for (unsigned int i = 1; i < 10; ++i)
    {
        if (maxDigit.probability < probs(i, 1))
            maxDigit = {i, probs(i, 1)};
    }
    return maxDigit;
}

