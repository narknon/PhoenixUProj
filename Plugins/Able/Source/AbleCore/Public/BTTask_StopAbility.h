#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "EAblAbilityTaskResult.h"
#include "Templates/SubclassOf.h"
#include "BTTask_StopAbility.generated.h"

class UAblAbility;

UCLASS(Blueprintable)
class ABLECORE_API UBTTask_StopAbility : public UBTTaskNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CancelActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> Ability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAblAbilityTaskResult> ResultToUse;
    
    UBTTask_StopAbility();
};

