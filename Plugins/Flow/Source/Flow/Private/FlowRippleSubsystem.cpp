#include "FlowRippleSubsystem.h"

class USceneComponent;

void UFlowRippleSubsystem::UnregisterDynamicRippleSource(USceneComponent* Attachment) {
}

void UFlowRippleSubsystem::RemovePersistentRippleSource(USceneComponent* Requester) {
}

void UFlowRippleSubsystem::RegisterDynamicRippleSource(const FFlowDynamicRippleRequest& Request) {
}

void UFlowRippleSubsystem::AddRipple(const FVector& PositionWorld, float Intensity, float Radius, float LifeTime, float ForceOverLifetime) {
}

void UFlowRippleSubsystem::AddPersistentRippleSource(USceneComponent* Requester, float Intensity, float Radius, float OscillationFrequency) {
}

UFlowRippleSubsystem::UFlowRippleSubsystem() {
    this->PlayerRenderTarget = NULL;
}

