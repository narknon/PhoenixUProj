#include "FlyingBroom_AnimInstance.h"

void UFlyingBroom_AnimInstance::AnimNotify_ThrowQuaffleFinished() {
}

void UFlyingBroom_AnimInstance::AnimNotify_CollisionResponseEnded() {
}

void UFlyingBroom_AnimInstance::AnimNotify_BarrelRollExited() {
}

UFlyingBroom_AnimInstance::UFlyingBroom_AnimInstance() {
    this->Turn = 0.00f;
    this->Lift = 0.00f;
    this->Speed = 0.00f;
    this->bIsFlying = false;
    this->bBarrelRollLeft = false;
    this->bBarrelRollRight = false;
    this->bIsStrafing = false;
    this->bHasHitUnknown = false;
    this->bIsThrowingQuaffle = false;
    this->bHasHitCharacterOnBroom = false;
    this->bHasHitCreature = false;
    this->bHasHitCharacter = false;
}

