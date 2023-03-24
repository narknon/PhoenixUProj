#include "SeasonChangerDelegate.h"

ASeasonChangerDelegate::ASeasonChangerDelegate(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DisableSeasonChanges = false;
    this->SeasonOverride = ESeasonOverride::SO_NONE;
}

