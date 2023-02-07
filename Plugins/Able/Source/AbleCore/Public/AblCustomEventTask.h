#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EAblAbilityTaskRealm.h"
#include "AblCustomEventTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblCustomEventTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName m_EventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAblAbilityTaskRealm m_TaskRealm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNotifyOtherAbilitiesOnChannel;
    
public:
    UAblCustomEventTask();
};

