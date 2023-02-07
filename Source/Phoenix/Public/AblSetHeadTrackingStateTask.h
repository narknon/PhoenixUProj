#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EHeadTrackingPriority.h"
#include "EHeadTrackingState.h"
#include "AblSetHeadTrackingStateTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblSetHeadTrackingStateTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EHeadTrackingState::Type> HeadTrackingState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseEndState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EHeadTrackingState::Type> EndHeadTrackingState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EHeadTrackingPriority::Type> HeadTrackingPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBroadcastChange;
    
public:
    UAblSetHeadTrackingStateTask();
};

