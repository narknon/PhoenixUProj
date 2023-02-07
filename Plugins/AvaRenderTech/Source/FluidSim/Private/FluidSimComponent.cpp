#include "FluidSimComponent.h"

class UCurveLinearColor;

void UFluidSimComponent::SetVorticityTrails(float VorticityTrailsIn) {
}

void UFluidSimComponent::SetVorticity(float VorticityIn) {
}

void UFluidSimComponent::SetVolumeScale(FVector VolumeScaleIn) {
}

void UFluidSimComponent::SetVolumeMotion(bool VolumeMotionIn) {
}

void UFluidSimComponent::SetVelocityDissipation(float VelocityDissipationIn) {
}

void UFluidSimComponent::SetTimeStep(float TimeStepIn) {
}

void UFluidSimComponent::SetSourceDissipation(float SourceDissipationIn) {
}

void UFluidSimComponent::SetMotionVectorStrength(float MotionVectorStrengthIn) {
}

void UFluidSimComponent::SetFadeEdges(bool FadeEdgesIn) {
}

void UFluidSimComponent::SetEnabled(bool EnabledIn) {
}

void UFluidSimComponent::SetDrawDebugBounds(bool DrawDebugBoundsIn) {
}

void UFluidSimComponent::SetDensity(float DensityIn) {
}

void UFluidSimComponent::SetComputeDimensions(FVector ComputeDimensionsIn) {
}

void UFluidSimComponent::SetColorIntensity(float ColorIntensityIn) {
}

void UFluidSimComponent::SetColorCurveScale(float ColorCurveScaleIn) {
}

void UFluidSimComponent::SetColorCurve(UCurveLinearColor* ColorCurveIn) {
}

void UFluidSimComponent::SetBuoyancyGravity(FVector BuoyancyGravityIn) {
}

float UFluidSimComponent::GetVorticityTrails() {
    return 0.0f;
}

float UFluidSimComponent::GetVorticity() {
    return 0.0f;
}

FVector UFluidSimComponent::GetVolumeScale() {
    return FVector{};
}

bool UFluidSimComponent::GetVolumeMotion() {
    return false;
}

float UFluidSimComponent::GetVelocityDissipation() {
    return 0.0f;
}

float UFluidSimComponent::GetTimeStep() {
    return 0.0f;
}

float UFluidSimComponent::GetMotionVectorStrength() {
    return 0.0f;
}

bool UFluidSimComponent::GetFadeEdges() {
    return false;
}

bool UFluidSimComponent::GetEnabled() {
    return false;
}

bool UFluidSimComponent::GetDrawDebugBounds() {
    return false;
}

float UFluidSimComponent::GetDensity() {
    return 0.0f;
}

FVector UFluidSimComponent::GetComputeDimensions() {
    return FVector{};
}

float UFluidSimComponent::GetColorIntensity() {
    return 0.0f;
}

float UFluidSimComponent::GetColorCurveScale() {
    return 0.0f;
}

UCurveLinearColor* UFluidSimComponent::GetColorCurve() {
    return NULL;
}

FVector UFluidSimComponent::GetBuoyancyGravity() {
    return FVector{};
}

UFluidSimComponent::UFluidSimComponent() {
}

