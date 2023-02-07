#include "OctaveNoiseParams.h"

FOctaveNoiseParams::FOctaveNoiseParams() {
    this->Octaves = 0;
    this->OctaveMode = EPerlinNoiseOctaveMode::All;
    this->OctavePersistence = 0.00f;
    this->BaseFrequency = 0.00f;
    this->Amplitude = 0.00f;
    this->Seed = 0.00f;
    this->bTilable = false;
}

