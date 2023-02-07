#pragma once
#include "CoreMinimal.h"
#include "SpellLevelData.h"
#include "ApparitionLevelData.generated.h"

USTRUCT(BlueprintType)
struct FApparitionLevelData : public FSpellLevelData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TapDistance;
    
    PHOENIX_API FApparitionLevelData();
};

