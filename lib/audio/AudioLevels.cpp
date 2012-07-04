#include "AudioLevels.h"

AudioLevels::AudioLevels(int input_size, int output_size)
{
    resize(input_size, output_size);
}

float AudioLevels::getMatrixValue(int input, int output)
{
    return mMatrix[input*InputSize()+output];
}

void AudioLevels::setMatrixValue(int input, int output, float val)
{
    if (val >= 0.0 && val <= 1.0) mMatrix[input*InputSize()+output] = val;
}

void AudioLevels::resize(int input_size, int output_size)
{
    std::vector<float> old_matrix = mMatrix;
    int index, old_index;
    mMatrix.clear();
    
    for (int i=0; i < input_size; i++) {
        for (int j=0; j < output_size; j++) {
            index = i*input_size + j;
            old_index = i*InputSize() + j;
            if (old_index < old_matrix.size()) mMatrix.push_back(old_matrix[old_index]);
            else {
                if (i == j) mMatrix.push_back(1.0);
                else mMatrix.push_back(0.0);
            }
        }
    }
    mInputSize = input_size;
    mOutputSize = output_size;
}
