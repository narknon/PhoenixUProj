#pragma once
#include "CoreMinimal.h"
#include "BTTask_PlayAbilityBase.h"
#include "Templates/SubclassOf.h"
#include "BTTask_PlayAbility.generated.h"

class UAblAbility;

UCLASS(Blueprintable)
class ABLECORE_API UBTTask_PlayAbility : public UBTTask_PlayAbilityBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> Ability;
    
    UBTTask_PlayAbility();
};

