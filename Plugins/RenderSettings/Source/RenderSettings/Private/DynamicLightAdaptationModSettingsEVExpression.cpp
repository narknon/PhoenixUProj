#include "DynamicLightAdaptationModSettingsEVExpression.h"

UDynamicLightAdaptationModSettingsEVExpression::UDynamicLightAdaptationModSettingsEVExpression() {
    this->ModProperty = ELightAdapatationEVProperty::BaseEV;
    this->ModOp = ELightAdapatationEVModOp::Set;
    this->Expression = NULL;
}

