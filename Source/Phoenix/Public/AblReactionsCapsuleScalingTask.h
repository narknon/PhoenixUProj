#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AlphaBlend.h"
#include "AblReactionsCapsuleScalingTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblReactionsCapsuleScalingTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseHeightAsRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RadiusMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HalfHeightMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRestoreAtEndTask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAlphaBlend BlendTime;
    
public:
    UAblReactionsCapsuleScalingTask();
};

