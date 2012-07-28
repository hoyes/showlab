#ifndef AUDIO_LEVELS_H
#define AUDIO_LEVELS_H

#include <vector>
#include <memory>

class AudioLevels
{
private:
    float mVolume;
    int mInputSize, mOutputSize;
    std::vector<float> mMatrix;
public:
    AudioLevels(int input_size = 0, int output_size = 0);
    
    float Volume() { return mVolume; }
    void Volume(float v) { mVolume = v; }
    
    int InputSize() { return mInputSize; }
    void InputSize(int v) { mInputSize = v; }
    
    int OutputSize() { return mOutputSize; }
    void OutputSize(int v) { mOutputSize = v; }
    
    float getMatrixValue(int input, int output);
    void setMatrixValue(int input, int output, float val);
    
    void resize(int input_size, int output_size);
};

typedef shared_ptr<AudioLevels> AudioLevelsRef;

#endif
