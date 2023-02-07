#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblPhysicalReactionBlendBackTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblPhysicalReactionBlendBackTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForcePopOutOfRagdollImmediately;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideBlendDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendDurationOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStationaryCapsuleWhileBlending;
    
    UAblPhysicalReactionBlendBackTask();
};

