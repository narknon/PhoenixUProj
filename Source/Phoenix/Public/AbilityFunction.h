#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ESpellUpgrades.h"
#include "AbilityFunction.generated.h"

USTRUCT(BlueprintType)
struct FAbilityFunction {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag GameplayTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESpellUpgrades Upgrade;
    
    PHOENIX_API FAbilityFunction();
};

