#include "CreatureSettings.h"

UCreatureSettings::UCreatureSettings() {
    this->HappinessThresholdForPerkConsideration = 20.00f;
    this->HappinessStartValueWhenCaptured = 0.00f;
    this->HappinessStartValue1stGeneration = 100.00f;
    this->HappinessStartValue2ndGeneration = 100.00f;
    this->HappinessCapWhenCaptured = 100.00f;
    this->HappinessCap1stGeneration = 100.00f;
    this->HappinessCap2ndGeneration = 100.00f;
    this->HappinessGainedWhenFed = 11.00f;
    this->HappinessGainedWhenInteractedWith = 11.00f;
    this->HappinessGainedWhenByproductHarvested = 11.00f;
    this->MinTimeBetweenHappinessChangesFromDamage = 0.30f;
    this->HappinessForConsecutiveDamage.AddDefaulted(5);
    this->TimeoutForConsecutiveDamageReset = 60.00f;
    this->HappinessForNeighborDeath = -0.05f;
    this->ConflictPreventedDurationSeconds = 86400.00f;
    this->ByproductProductionLock = TEXT("Nurture_ByproductProduction");
    this->ByproductCollectionLock = TEXT("Nurture_ByproductCollection");
    this->NurturingSpaceContextLock = TEXT("Nurture_NurturingSpaces");
    this->FemaleEconomyValuePercent = 110.00f;
    this->AlbinoEconomyValuePercent = 200.00f;
    this->CommonColorVariationEconomyValuePercent = 100.00f;
    this->HappinessEconomyValuePercent = 1.00f;
    this->RepopulationTimeHour = 6;
    this->RepopulationExpiryTimeMinutes = 60;
    this->CreatureFeedItemID = TEXT("CreatureFeed");
    this->DefaultFeedConversionTimeSec = 1;
    this->DefaultToyID = TEXT("CreatureBallToy");
    this->PreferredGroundSlopeAngleMax = 22.00f;
    this->PreferredDistanceToPathMin = 250.00f;
    this->PreloadedAssetPaths.AddDefaulted(13);
}

