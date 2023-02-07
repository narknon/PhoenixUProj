#include "NiagaraStarrySkySwitchableHighlightComponent.h"

class UNiagaraSystem;
class UObject;

void UNiagaraStarrySkySwitchableHighlightComponent::SupportedHighlightConstellations(int32& Constellations) {
}

bool UNiagaraStarrySkySwitchableHighlightComponent::StarrySkyStartHighlightings(UObject* WorldContextObject, TArray<FName> HighlightConstellationNames, FName HighlightStarName, float InitialModulate) {
    return false;
}

bool UNiagaraStarrySkySwitchableHighlightComponent::StarrySkyStartHighlighting(UObject* WorldContextObject, FName HighlightConstellationName, FName HighlightStarName, float InitialModulate) {
    return false;
}

bool UNiagaraStarrySkySwitchableHighlightComponent::StarrySkySetHighlightParameters(UObject* WorldContextObject, FStarrySkyHighlightParameters Parameters) {
    return false;
}

bool UNiagaraStarrySkySwitchableHighlightComponent::StarrySkySetHighlightModulate(UObject* WorldContextObject, float Modulate) {
    return false;
}

bool UNiagaraStarrySkySwitchableHighlightComponent::StarrySkyEndHighlighting(UObject* WorldContextObject) {
    return false;
}

void UNiagaraStarrySkySwitchableHighlightComponent::SetMode(ESwitchableStarrySkyMode Mode) {
}

void UNiagaraStarrySkySwitchableHighlightComponent::SetHighlightSystem(UNiagaraSystem* NiagaraSystem) {
}

void UNiagaraStarrySkySwitchableHighlightComponent::SetHighlightStar(FName StarName) {
}

void UNiagaraStarrySkySwitchableHighlightComponent::SetHighlights(TArray<FName> ConstellationNames, FName StarName) {
}

void UNiagaraStarrySkySwitchableHighlightComponent::SetHighlightConstellations(TArray<FName> ConstellationNames) {
}

void UNiagaraStarrySkySwitchableHighlightComponent::SetHighlightConstellation(FName ConstellationName) {
}

void UNiagaraStarrySkySwitchableHighlightComponent::SetHighlight(FName ConstellationName, FName StarName) {
}

void UNiagaraStarrySkySwitchableHighlightComponent::LoadHighlightSystem(TSoftObjectPtr<UNiagaraSystem> NiagaraSystem) {
}

bool UNiagaraStarrySkySwitchableHighlightComponent::IsHighlightLoadedSystem(TSoftObjectPtr<UNiagaraSystem> NiagaraSystem) const {
    return false;
}

void UNiagaraStarrySkySwitchableHighlightComponent::GetMode(ESwitchableStarrySkyMode& Mode) {
}

void UNiagaraStarrySkySwitchableHighlightComponent::ClearHighlights() {
}

void UNiagaraStarrySkySwitchableHighlightComponent::ClearHighlightConstellations() {
}

UNiagaraStarrySkySwitchableHighlightComponent::UNiagaraStarrySkySwitchableHighlightComponent() {
    this->HighlightModulate = 1.00f;
    this->HighlightStarrySkySystem = NULL;
    this->bUseCameraAsOriginForHighlighting = true;
    this->CurrentMode = ESwitchableStarrySkyMode::Normal;
    this->bHighlightForDefocus = false;
}

