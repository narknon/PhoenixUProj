#include "Patronus_Character.h"
#include "AnimationComponent.h"

APatronus_Character::APatronus_Character() {
    this->AnimationComponent = CreateDefaultSubobject<UAnimationComponent>(TEXT("AnimationComponent"));
    this->RootMotionTranslationScale = 1.00f;
}

