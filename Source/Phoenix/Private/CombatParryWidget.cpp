#include "CombatParryWidget.h"

class UObject;

void UCombatParryWidget::CombatParryInfoTimerFinished(const UObject* Caller, const int32 WindowID, int32 ParryType) {
}

UCombatParryWidget::UCombatParryWidget() {
    this->CombatParryButtonCallout0 = NULL;
    this->CombatParryButtonCallout1 = NULL;
    this->CombatParryButtonCallout2 = NULL;
    this->CombatParryButtonCalloutForOutro = NULL;
}

