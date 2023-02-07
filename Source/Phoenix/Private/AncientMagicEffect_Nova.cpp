#include "AncientMagicEffect_Nova.h"

class UObject;

void UAncientMagicEffect_Nova::NovaFinished(const UObject* Object) {
}

UAncientMagicEffect_Nova::UAncientMagicEffect_Nova() {
    this->NovaExpandSpeed = 25.00f;
    this->NovaExpandDistance = 3000.00f;
    this->HidePlayerWhileActive = false;
    this->NovaActor = NULL;
}

