#include "StarCatalogConstellationLimits.h"

FStarCatalogConstellationLimits::FStarCatalogConstellationLimits() {
    this->DefaultLimitConstellationStars = 0;
    this->ConstellationNameMagnitudeCutoff = 0.00f;
    this->bUseConstellationStarsLimit = false;
    this->bUseDefaultConstellationStarsLimit = false;
    this->bUseConstellationNameMagnitudeCutoff = false;
}

