#include "PHX_Biped_Preview_Actor.h"
#include "CustomizableCharacterComponent.h"

APHX_Biped_Preview_Actor::APHX_Biped_Preview_Actor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Customization = CreateDefaultSubobject<UCustomizableCharacterComponent>(TEXT("Customization"));
}

