#include "CompanionConfigData.h"

UCompanionConfigData::UCompanionConfigData() {
    this->SoCapStatusOnDismissal = SOCIALCAPITAL_STATUS_DISLIKE;
    this->CompanionForbiddenAreaMessage = TEXT("Companion waiting...");
    this->ForcedCompanionPlaybackProbability = 0.75f;
}

