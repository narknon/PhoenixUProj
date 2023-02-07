#pragma once
#include "CoreMinimal.h"
#include "SpellLevelData.h"
#include "ArrestoMomentumLevelData.generated.h"

USTRUCT(BlueprintType)
struct FArrestoMomentumLevelData : public FSpellLevelData {
    GENERATED_BODY()
public:
    PHOENIX_API FArrestoMomentumLevelData();
};

