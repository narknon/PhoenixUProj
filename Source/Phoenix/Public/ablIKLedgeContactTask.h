#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ablIKLedgeContactTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablIKLedgeContactTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendInDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendOutDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLockHandsToLedge;
    
    UablIKLedgeContactTask();
};

