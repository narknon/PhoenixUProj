#include "LerpVolumesLocalEvaluationComponent.h"

class ULerpVolumesLibrary;

void ULerpVolumesLocalEvaluationComponent::SetUpdatesEnabled(bool Enable) {
}

void ULerpVolumesLocalEvaluationComponent::SetLocalLibrary(ULerpVolumesLibrary* NewLocalLibrary) {
}

bool ULerpVolumesLocalEvaluationComponent::IsLocalVector(FName VariableName) const {
    return false;
}

bool ULerpVolumesLocalEvaluationComponent::IsLocalUnitDirection(FName VariableName) const {
    return false;
}

bool ULerpVolumesLocalEvaluationComponent::IsLocalTag(FName VariableName) const {
    return false;
}

bool ULerpVolumesLocalEvaluationComponent::IsLocalScalar(FName VariableName) const {
    return false;
}

bool ULerpVolumesLocalEvaluationComponent::IsLocalInteger(FName VariableName) const {
    return false;
}

bool ULerpVolumesLocalEvaluationComponent::IsLocalColor(FName VariableName) const {
    return false;
}

bool ULerpVolumesLocalEvaluationComponent::GetLocalVector(FName VariableName, FVector& VariableValue) const {
    return false;
}

bool ULerpVolumesLocalEvaluationComponent::GetLocalUnitDirection(FName VariableName, FVector& VariableValue) const {
    return false;
}

void ULerpVolumesLocalEvaluationComponent::GetLocalType(FName VariableName, ELerpVolumesInterpolantType& VariableType) const {
}

bool ULerpVolumesLocalEvaluationComponent::GetLocalTag(FName VariableName, FString& VariableValue) const {
    return false;
}

bool ULerpVolumesLocalEvaluationComponent::GetLocalScalar(FName VariableName, float& VariableValue) const {
    return false;
}

bool ULerpVolumesLocalEvaluationComponent::GetLocalInteger(FName VariableName, int32& VariableValue) const {
    return false;
}

bool ULerpVolumesLocalEvaluationComponent::GetLocalColor(FName VariableName, FLinearColor& VariableValue) const {
    return false;
}

void ULerpVolumesLocalEvaluationComponent::ForceUpdate() {
}

bool ULerpVolumesLocalEvaluationComponent::AreUpdatesEnabled() const {
    return false;
}

ULerpVolumesLocalEvaluationComponent::ULerpVolumesLocalEvaluationComponent() {
    this->SecondsPerUpdate = 1.00f;
    this->DistanceThreshold = 50.00f;
    this->bUseDistanceThreshold = true;
    this->bUpdatesEnabled = true;
    this->LocalLibrary = NULL;
    this->UpdateCountdown = 0.00f;
    this->bLastPositionValid = false;
}

