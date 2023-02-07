#include "ModFilter_LootDrop_RarityPercentageTarget.h"

UModFilter_LootDrop_RarityPercentageTarget::UModFilter_LootDrop_RarityPercentageTarget() {
    this->ComparisonOperator = EValueComparison::Less;
    this->TargetPercent = 0.00f;
}

