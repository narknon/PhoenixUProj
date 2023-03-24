#include "HighContrastGameplayMarkupOtherActor.h"
#include "HighContrastGameplayMarkupOtherActorComponent.h"

AHighContrastGameplayMarkupOtherActor::AHighContrastGameplayMarkupOtherActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Component = CreateDefaultSubobject<UHighContrastGameplayMarkupOtherActorComponent>(TEXT("HighContrastGameplayMarkupOtherActorComponent0"));
}

