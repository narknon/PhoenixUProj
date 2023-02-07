#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EManagedFacialAnimationPriority.h"
#include "FacialAnimation.h"
#include "ablFacialAnimationStateTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablFacialAnimationStateTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFacialAnimation FacialAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EManagedFacialAnimationPriority FacialAnimationPriority;
    
public:
    UablFacialAnimationStateTask();
};

