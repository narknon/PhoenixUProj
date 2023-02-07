#include "CreatureDefinition.h"

bool UCreatureDefinition::IsOffspring() const {
    return false;
}

bool UCreatureDefinition::IsEggLaying() const {
    return false;
}

bool UCreatureDefinition::IsEgg() const {
    return false;
}

bool UCreatureDefinition::IsAdult() const {
    return false;
}

FName UCreatureDefinition::GetTypeID() const {
    return NAME_None;
}

FTimespan UCreatureDefinition::GetPregnancyDuration() const {
    return FTimespan{};
}

FName UCreatureDefinition::GetPreferredToyID() const {
    return NAME_None;
}

float UCreatureDefinition::GetPlayWithToyHappinessPercentage() const {
    return 0.0f;
}

bool UCreatureDefinition::GetOnlyCapturableWhenNearDeathKneeling() const {
    return false;
}

FName UCreatureDefinition::GetOffspringCreatureTypeID() const {
    return NAME_None;
}

int32 UCreatureDefinition::GetNumCapturingGates() const {
    return 0;
}

bool UCreatureDefinition::GetIsCarnivore() const {
    return false;
}

bool UCreatureDefinition::GetIsAggressive() const {
    return false;
}

FTimespan UCreatureDefinition::GetHatchingDuration() const {
    return FTimespan{};
}

FName UCreatureDefinition::GetEggTypeID() const {
    return NAME_None;
}

TArray<FName> UCreatureDefinition::GetConflictTypeIDs() const {
    return TArray<FName>();
}

int32 UCreatureDefinition::GetCompletedYearForCapture() const {
    return 0;
}

FTimespan UCreatureDefinition::GetChildhoodDuration() const {
    return FTimespan{};
}

float UCreatureDefinition::GetCapturingTime() const {
    return 0.0f;
}

int32 UCreatureDefinition::GetCapturingDistanceMax() const {
    return 0;
}

bool UCreatureDefinition::GetCanBeCaptured() const {
    return false;
}

FName UCreatureDefinition::GetByproductID() const {
    return NAME_None;
}

int32 UCreatureDefinition::GetByproductHarvestCount() const {
    return 0;
}

float UCreatureDefinition::GetByproductCooldownTimeSec() const {
    return 0.0f;
}

int32 UCreatureDefinition::GetBaseEconomyValue() const {
    return 0;
}

FName UCreatureDefinition::GetAdultCreatureTypeID() const {
    return NAME_None;
}

FName UCreatureDefinition::GetAchievementForCapturing() const {
    return NAME_None;
}

UCreatureDefinition::UCreatureDefinition() {
}

