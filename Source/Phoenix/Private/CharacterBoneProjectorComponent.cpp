#include "CharacterBoneProjectorComponent.h"
#include "CharacterBoneProjector.h"

UCharacterBoneProjectorComponent::UCharacterBoneProjectorComponent() {
    this->Projector = CreateDefaultSubobject<UCharacterBoneProjector>(TEXT("Projector"));
    this->bDebugDraw = true;
}

