#include "WorldFXPerWorldSettings.h"

FWorldFXPerWorldSettings::FWorldFXPerWorldSettings() {
    this->DefaultAudioDistanceMeters = 0.00f;
    this->DefaultParticleDistanceMeters = 0.00f;
    this->DefaultGenericDistanceMeters = 0.00f;
    this->MaxAudioDistanceMeters = 0.00f;
    this->MaxParticleDistanceMeters = 0.00f;
    this->MaxGenericDistanceMeters = 0.00f;
    this->OctreeExpandWorldBoundsFactor = 0.00f;
    this->bDisableAllCulling = false;
}

