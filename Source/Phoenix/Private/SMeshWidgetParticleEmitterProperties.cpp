#include "SMeshWidgetParticleEmitterProperties.h"

FSMeshWidgetParticleEmitterProperties::FSMeshWidgetParticleEmitterProperties() {
    this->EmitterType = ESMeshWidgetParticleEmitterType::Continuous;
    this->RunOnStart = false;
    this->FixToWidgetGeometry = false;
    this->ParticlesPerSecond = 0;
    this->MinEmissionAngle = 0.00f;
    this->MaxEmissionAngle = 0.00f;
    this->MinLifeTime = 0.00f;
    this->MaxLifeTime = 0.00f;
    this->MinSpeed = 0.00f;
    this->MaxSpeed = 0.00f;
    this->StartScale = 0.00f;
    this->EndScale = 0.00f;
    this->RandomForceRateOfChange = 0.00f;
    this->RandomForceScaleOfChange = 0.00f;
}

