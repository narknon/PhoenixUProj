#include "Placeholder.h"
#include "Components/SceneComponent.h"

APlaceholder::APlaceholder() {
    this->SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
}

