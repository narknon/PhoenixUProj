#include "AblBlendSpaceParameterGetter_BodyLean2D.h"

UAblBlendSpaceParameterGetter_BodyLean2D::UAblBlendSpaceParameterGetter_BodyLean2D() {
    this->MinMaxForwardAcceleration = 800.00f;
    this->MinMaxSideAcceleration = 800.00f;
    this->InterpAlphaX = 8.00f;
    this->InterpAlphaY = 8.00f;
}

