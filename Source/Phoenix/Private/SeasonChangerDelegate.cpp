#include "SeasonChangerDelegate.h"

ASeasonChangerDelegate::ASeasonChangerDelegate() {
    this->DisableSeasonChanges = false;
    this->SeasonOverride = ESeasonOverride::SO_NONE;
}

