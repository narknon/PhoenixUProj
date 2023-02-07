#include "SuperSlamTarget.h"
#include "Components/BoxComponent.h"

ASuperSlamTarget::ASuperSlamTarget() {
    this->SceneComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
}

