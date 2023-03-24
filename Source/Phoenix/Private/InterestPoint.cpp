#include "InterestPoint.h"
#include "Components/SceneComponent.h"

AInterestPoint::AInterestPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
}

