#include "AkComponent.h"

class UAkAudioEvent;
class UAkAuxBus;
class UAkComponent;
class UAkSwitchValue;
class UAkTrigger;

void UAkComponent::UseReverbVolumes(bool inUseReverbVolumes) {
}

void UAkComponent::UseEarlyReflections(UAkAuxBus* AuxBus, int32 Order, float BusSendGain, float MaxPathLength, bool SpotReflectors, const FString& AuxBusName) {
}

void UAkComponent::SetWantsOnUpdateTransform(bool bInWantsOnUpdateTranform) {
}

void UAkComponent::SetSwitchPropagating(UAkSwitchValue* SwitchValue, const FString& SwitchGroup, const FString& SwitchState) {
}

void UAkComponent::SetSwitch(UAkSwitchValue* SwitchValue, const FString& SwitchGroup, const FString& SwitchState) {
}

void UAkComponent::SetStopWhenOwnerDestroyed(bool bStopWhenOwnerDestroyed) {
}

void UAkComponent::SetOutputBusVolume(float BusVolume) {
}

void UAkComponent::SetListeners(const TArray<UAkComponent*>& Listeners) {
}

void UAkComponent::SetGameObjectRadius(float in_outerRadius, float in_innerRadius) {
}

void UAkComponent::SetEarlyReflectionsVolume(float SendVolume) {
}

void UAkComponent::SetEarlyReflectionsAuxBus(const FString& AuxBusName) {
}

void UAkComponent::SetAttenuationScalingFactor(float Value) {
}

void UAkComponent::PostTrigger(UAkTrigger* TriggerValue, const FString& Trigger) {
}

void UAkComponent::PostAssociatedAkEventAndWaitForEndAsync(int32& PlayingID, const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo) {
}

int32 UAkComponent::PostAssociatedAkEventAndWaitForEnd(const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo) {
    return 0;
}

int32 UAkComponent::PostAkEventByName(const FString& in_EventName) {
    return 0;
}

void UAkComponent::PostAkEventAndWaitForEndAsync(UAkAudioEvent* AkEvent, int32& PlayingID, const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo) {
}

int32 UAkComponent::PostAkEventAndWaitForEnd(UAkAudioEvent* AkEvent, const FString& in_EventName, const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo) {
    return 0;
}

void UAkComponent::OcclusionRefreshStackSetDefault(float RefreshInterval) {
}

void UAkComponent::OcclusionRefreshStackRemove(int32 StackHandle) {
}

int32 UAkComponent::OcclusionRefreshStackAdd(float RefreshInterval, int32 Priority) {
    return 0;
}

void UAkComponent::MasterTickThrottlerSetNoTickRadius(const float NoTickRadiusMeters) {
}

float UAkComponent::GetAttenuationRadius() const {
    return 0.0f;
}

UAkComponent::UAkComponent() {
    this->bUseSpatialAudio = false;
    this->OcclusionCollisionChannel = ECC_Visibility;
    this->EnableSpotReflectors = false;
    this->OuterRadius = 0.00f;
    this->InnerRadius = 0.00f;
    this->EarlyReflectionAuxBus = NULL;
    this->EarlyReflectionOrder = 0;
    this->EarlyReflectionBusSendGain = 1.00f;
    this->EarlyReflectionMaxPathLength = 0.00f;
    this->roomReverbAuxBusGain = 0.00f;
    this->diffractionMaxEdges = 0;
    this->diffractionMaxPaths = 0;
    this->diffractionMaxPathLength = 0.00f;
    this->DrawFirstOrderReflections = false;
    this->DrawSecondOrderReflections = false;
    this->DrawHigherOrderReflections = false;
    this->DrawDiffraction = false;
    this->StopWhenOwnerDestroyed = true;
    this->AttenuationScalingFactor = 1.00f;
    this->OcclusionRefreshInterval = 0.20f;
    this->OcclusionSecondaryTracePoints = 12;
    this->bSkipOcclusionCalculation = false;
    this->bSpawnedByAnimNotify = false;
    this->bUseReverbVolumes = true;
    this->bComputeDoppler = false;
}

