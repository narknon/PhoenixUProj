#include "HighContrastGameplayMarkupOtherActor.h"
#include "HighContrastGameplayMarkupOtherActorComponent.h"

AHighContrastGameplayMarkupOtherActor::AHighContrastGameplayMarkupOtherActor() {
    this->Component = CreateDefaultSubobject<UHighContrastGameplayMarkupOtherActorComponent>(TEXT("HighContrastGameplayMarkupOtherActorComponent0"));
}

