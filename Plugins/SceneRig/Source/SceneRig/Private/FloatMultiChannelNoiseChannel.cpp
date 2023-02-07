#include "FloatMultiChannelNoiseChannel.h"

FFloatMultiChannelNoiseChannel::FFloatMultiChannelNoiseChannel() {
    this->Frequency = 0.00f;
    this->Amplitude = 0.00f;
    this->TimeOffset = 0.00f;
    this->Waveform = EFloatMultiChannelNoiseWaveform::CosineWave;
    this->Enabled = false;
}

