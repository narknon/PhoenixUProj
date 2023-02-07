#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblNpcTargetingModifierTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblNpcTargetingModifierTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bModifyTargetingModifierAtTaskStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetingModifierAtTaskStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bModifyTargetingModifierAtTaskEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetingModifierAtTaskEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRestoreTargetingModifierAtTaskEnd;
    
public:
    UAblNpcTargetingModifierTask();
};

