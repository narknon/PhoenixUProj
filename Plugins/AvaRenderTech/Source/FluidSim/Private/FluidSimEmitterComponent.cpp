#include "FluidSimEmitterComponent.h"

void UFluidSimEmitterComponent::SetMotionVectorStrength(float MotionVectorStrengthIn) {
}

void UFluidSimEmitterComponent::SetEmitterPos(const FVector4& EmitterPosIn) {
}

void UFluidSimEmitterComponent::SetEmitterMultiplier(float EmitterMultiplierIn) {
}

void UFluidSimEmitterComponent::SetEmitterDir(const FVector4& EmitterDirIn) {
}

void UFluidSimEmitterComponent::SetEmitterBias(float EmitterBiasIn) {
}

float UFluidSimEmitterComponent::GetMotionVectorStrength() {
    return 0.0f;
}

float UFluidSimEmitterComponent::GetEmitterMultiplier() {
    return 0.0f;
}

FVector4 UFluidSimEmitterComponent::GetEmitterDir() {
    return FVector4{};
}

float UFluidSimEmitterComponent::GetEmitterBias() {
    return 0.0f;
}

UFluidSimEmitterComponent::UFluidSimEmitterComponent() {
}

