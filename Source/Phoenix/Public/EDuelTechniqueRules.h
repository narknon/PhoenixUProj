#pragma once
#include "CoreMinimal.h"
#include "EDuelTechniqueRules.generated.h"

UENUM(BlueprintType)
enum class EDuelTechniqueRules : uint8 {
    ListEncounterRule,
    IncompleteRule,
    NumTimesSeenRule,
    TechniqueWeightRule,
    DifficultyRule,
    SpellCategoryRule,
    ItemRule,
    EnvironmentObstacleRule,
    DTCategoriesRule,
    EquippedSpellsRule,
};

