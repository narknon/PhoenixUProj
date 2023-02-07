#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EAblAbilityTargetType.h"
#include "Templates/SubclassOf.h"
#include "AblPlayAbilityByChannelTask.generated.h"

class UAblAbility;
class UAblTaskCondition;

UCLASS(Blueprintable, EditInlineNew)
class UAblPlayAbilityByChannelTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> m_Ability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAblAbilityTargetType> m_Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAblAbilityTargetType> m_Instigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName m_ChannelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblTaskCondition*> TaskConditions;
    
public:
    UAblPlayAbilityByChannelTask();
};

