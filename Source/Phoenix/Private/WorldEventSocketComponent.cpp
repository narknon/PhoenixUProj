#include "WorldEventSocketComponent.h"

class UShapeComponent;
class USplineComponent;

void UWorldEventSocketComponent::SetSocketOccupied(bool bInOccupied) {
}

bool UWorldEventSocketComponent::IsSocketOccupied() {
    return false;
}

USplineComponent* UWorldEventSocketComponent::GetSplineComponent() {
    return NULL;
}

FGameplayTagContainer UWorldEventSocketComponent::GetSocketDescriptors() const {
    return FGameplayTagContainer{};
}

UShapeComponent* UWorldEventSocketComponent::GetShapeComponent() {
    return NULL;
}

void UWorldEventSocketComponent::Construct_Implementation(const FTransform& Transform) {
}

UWorldEventSocketComponent::UWorldEventSocketComponent() {
    this->SplineComponent = NULL;
    this->ShapeComponent = NULL;
}

