#pragma once
#include "CoreMinimal.h"
#include "SpellLevelData.h"
#include "AvadaKedavraLevelData.generated.h"

USTRUCT(BlueprintType)
struct FAvadaKedavraLevelData : public FSpellLevelData {
    GENERATED_BODY()
public:
    PHOENIX_API FAvadaKedavraLevelData();
};

