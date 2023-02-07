#include "BTComposite_UtilitySelector.h"

UBTComposite_UtilitySelector::UBTComposite_UtilitySelector() {
    this->SelectionMethod = EUtilitySelectionMethod::HighestScore;
    this->WeightThreshold = 0.10f;
    this->bIgnoreRank = false;
}

