#include "SpringFollowActor.h"
#include "SpringFollowComponent.h"

void ASpringFollowActor::ResetPhysics() {
}

ASpringFollowActor::ASpringFollowActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bSpringsActive = true;
    this->Damping = 0.05f;
    this->RadialDamping = 0.05f;
    this->SpringFollow = CreateDefaultSubobject<USpringFollowComponent>(TEXT("SpringFollow"));
}

