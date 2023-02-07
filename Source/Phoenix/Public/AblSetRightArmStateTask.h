#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ERightArmPriority.h"
#include "ERightArmState.h"
#include "AblSetRightArmStateTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblSetRightArmStateTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ERightArmState::Type> RightArmState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseEndState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ERightArmState::Type> EndRightArmState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ERightArmPriority::Type> RightArmPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBroadcastChange;
    
public:
    UAblSetRightArmStateTask();
};

