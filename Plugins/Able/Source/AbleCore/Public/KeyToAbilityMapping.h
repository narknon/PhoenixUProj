#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Templates/SubclassOf.h"
#include "KeyToAbilityMapping.generated.h"

class UAblAbility;

USTRUCT(BlueprintType)
struct FKeyToAbilityMapping : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAdditive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> Ability;
    
    ABLECORE_API FKeyToAbilityMapping();
};

