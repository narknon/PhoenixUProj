#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Enemy_SpellOverrides.generated.h"

class USpellToolRecord;

USTRUCT(BlueprintType)
struct FEnemy_SpellOverrides {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer RequiredTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpellToolRecord* OverrideSpellToolRecord;
    
    PHOENIX_API FEnemy_SpellOverrides();
};

