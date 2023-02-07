#include "OdcObstacleComponent.h"

class UActorComponent;

void UOdcObstacleComponent::SetFlag(const FName FlagName) {
}

void UOdcObstacleComponent::ClearFlag(const FName FlagName) {
}

void UOdcObstacleComponent::AddComponentObstaclesBP(TArray<UActorComponent*> IncludeComponents, bool RemoveUnknownObstacles) {
}

void UOdcObstacleComponent::AddActorComponentObstaclesBP(bool RemoveUnknownObstacles, TArray<UActorComponent*> ExcludeComponents) {
}

UOdcObstacleComponent::UOdcObstacleComponent() {
    this->bExcludeIfParentHasAuthoredObstacle = true;
}

