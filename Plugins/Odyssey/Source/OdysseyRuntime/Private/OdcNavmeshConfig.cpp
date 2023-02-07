#include "OdcNavmeshConfig.h"

UOdcNavmeshConfig::UOdcNavmeshConfig() {
    this->DefaultPenaltyMultiplier = 10.00f;
    this->MarkupCollisionPreset = TEXT("NavMarkup");
    this->CollisionAreaUsageFlags.AddDefaulted(2);
    this->DefaultDrawDisttance = 10000.00f;
}

