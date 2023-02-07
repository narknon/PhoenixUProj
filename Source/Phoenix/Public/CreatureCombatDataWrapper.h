#pragma once
#include "CoreMinimal.h"
#include "CreatureCombatDataWrapper.generated.h"

class UCreatureCombatData;

USTRUCT(BlueprintType)
struct FCreatureCombatDataWrapper {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCreatureCombatData* CombatData;
    
    PHOENIX_API FCreatureCombatDataWrapper();
};

