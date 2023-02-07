#include "AncientMagicEffect_Test.h"

class AActor;

void UAncientMagicEffect_Test::CollisionDetected(AActor* Actor) {
}

UAncientMagicEffect_Test::UAncientMagicEffect_Test() {
    this->NovaClass = NULL;
    this->NovaExpandSpeed = 25.00f;
    this->NovaExpandDistance = 1500.00f;
    this->NovaActor = NULL;
}

