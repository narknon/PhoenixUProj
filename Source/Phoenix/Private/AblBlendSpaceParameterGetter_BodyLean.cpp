#include "AblBlendSpaceParameterGetter_BodyLean.h"

class AAmbulatory_Character;

void UAblBlendSpaceParameterGetter_BodyLean::OnTeleport(AAmbulatory_Character* Character, FVector AmountDisplaced, FRotator AmountRotated) {
}

UAblBlendSpaceParameterGetter_BodyLean::UAblBlendSpaceParameterGetter_BodyLean() {
    this->bUseSpringInterp = true;
    this->SpringHalflife = 0.08f;
}

