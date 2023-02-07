#include "TransformationFxInfoComponent.h"
#include "Components/BoxComponent.h"

UTransformationFxInfoComponent::UTransformationFxInfoComponent() {
    this->ObjectBounds = CreateDefaultSubobject<UBoxComponent>(TEXT("ObjectBounds"));
}

