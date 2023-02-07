#include "NiagaraStarrySkyHighlightComponent.h"

void UNiagaraStarrySkyHighlightComponent::SupportedHighlightConstellations(int32& Constellations) {
}

void UNiagaraStarrySkyHighlightComponent::SetHighlightStar(FName StarName) {
}

void UNiagaraStarrySkyHighlightComponent::SetHighlights(TArray<FName> ConstellationNames, FName StarName) {
}

void UNiagaraStarrySkyHighlightComponent::SetHighlightConstellations(TArray<FName> ConstellationNames) {
}

void UNiagaraStarrySkyHighlightComponent::SetHighlightConstellation(FName ConstellationName) {
}

void UNiagaraStarrySkyHighlightComponent::SetHighlight(FName ConstellationName, FName StarName) {
}

void UNiagaraStarrySkyHighlightComponent::ClearHighlights() {
}

void UNiagaraStarrySkyHighlightComponent::ClearHighlightConstellations() {
}

UNiagaraStarrySkyHighlightComponent::UNiagaraStarrySkyHighlightComponent() {
    this->HighlightModulate = 1.00f;
}

