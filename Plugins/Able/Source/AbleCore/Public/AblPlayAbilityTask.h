#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EAblAbilityTargetType.h"
#include "Templates/SubclassOf.h"
#include "AblPlayAbilityTask.generated.h"

class UAblAbility;

UCLASS(Blueprintable, EditInlineNew)
class UAblPlayAbilityTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> m_Ability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAblAbilityTargetType> m_Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAblAbilityTargetType> m_Instigator;
    
public:
    UAblPlayAbilityTask();
};

