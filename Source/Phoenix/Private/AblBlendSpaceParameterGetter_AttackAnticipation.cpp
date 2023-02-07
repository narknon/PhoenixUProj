#include "AblBlendSpaceParameterGetter_AttackAnticipation.h"

UAblBlendSpaceParameterGetter_AttackAnticipation::UAblBlendSpaceParameterGetter_AttackAnticipation() {
    this->DeadZoneAngle = 45.00f;
    this->ClampDesiredAngle = 180.00f;
    this->ToExtremesSpeed = 10.00f;
    this->ToZeroSpeed = 1.00f;
}

