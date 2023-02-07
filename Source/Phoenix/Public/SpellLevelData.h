#pragma once
#include "CoreMinimal.h"
#include "SpellLevelData.generated.h"

USTRUCT(BlueprintType)
struct FSpellLevelData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 SpellLevel;
    
    PHOENIX_API FSpellLevelData();
};

