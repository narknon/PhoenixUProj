#include "Placeholder.h"
#include "Components/SceneComponent.h"

APlaceholder::APlaceholder(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
}

