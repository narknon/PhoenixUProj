#pragma once
#include "CoreMinimal.h"
#include "ActiveAbility.generated.h"

class URPGAbilityBase;

USTRUCT(BlueprintType)
struct FActiveAbility {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URPGAbilityBase* Ability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URPGAbilityBase* Template;
    
    PHOENIX_API FActiveAbility();
};

