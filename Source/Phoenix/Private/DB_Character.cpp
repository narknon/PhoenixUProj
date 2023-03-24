#include "DB_Character.h"
#include "AnimationComponent.h"
#include "FacialComponent.h"
#include "CustomizableCharacterComponent.h"
#include "BipedStateComponent.h"
#include "Biped_MovementComponent.h"

ADB_Character::ADB_Character(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UBiped_MovementComponent>(TEXT("CharMoveComp"))) {
    this->ObjectStateComponent = CreateDefaultSubobject<UBipedStateComponent>(TEXT("BipedStateComponent"));
    this->Customization = CreateDefaultSubobject<UCustomizableCharacterComponent>(TEXT("Customization"));
    this->FacialComponent = CreateDefaultSubobject<UFacialComponent>(TEXT("FacialComponent"));
    this->AnimationComponent = CreateDefaultSubobject<UAnimationComponent>(TEXT("AnimationComponent"));
}

