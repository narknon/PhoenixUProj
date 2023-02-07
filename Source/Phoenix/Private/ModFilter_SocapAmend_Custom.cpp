#include "ModFilter_SocapAmend_Custom.h"


UModFilter_SocapAmend_Custom::UModFilter_SocapAmend_Custom() {
    this->bUseValueFilter = false;
    this->ComparisonOperator = EValueComparison::Less;
    this->ComparisonValue = 0;
    this->bUseSocialReasoningFilter = false;
    this->bUseSocialSemanticsFilter = false;
}

