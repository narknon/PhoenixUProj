#pragma once
#include "CoreMinimal.h"
#include "EDuelTechniqueCategory.generated.h"

UENUM(BlueprintType)
enum class EDuelTechniqueCategory : uint8 {
    CommonMechanicMastery,
    EnvironmentalOpportunities,
    SpecialEnemyOpportunities,
    SpecialToolSpellEncouragement,
    SpellCombos,
    TalentRequired,
};

