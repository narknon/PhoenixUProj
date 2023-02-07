#include "InterestPoint.h"
#include "Components/SceneComponent.h"

AInterestPoint::AInterestPoint() {
    this->SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
}

