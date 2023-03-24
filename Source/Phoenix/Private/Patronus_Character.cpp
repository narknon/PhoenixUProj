#include "Patronus_Character.h"
#include "AnimationComponent.h"

APatronus_Character::APatronus_Character(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AnimationComponent = CreateDefaultSubobject<UAnimationComponent>(TEXT("AnimationComponent"));
    this->RootMotionTranslationScale = 1.00f;
}

