#include "SuperSlamTarget.h"
#include "Components/BoxComponent.h"

ASuperSlamTarget::ASuperSlamTarget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SceneComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
}

