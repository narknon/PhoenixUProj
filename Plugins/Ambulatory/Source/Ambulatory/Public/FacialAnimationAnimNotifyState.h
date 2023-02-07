#pragma once
#include "CoreMinimal.h"
#include "EManagedFacialAnimationPriority.h"
#include "FacialAnimation.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "FacialAnimationAnimNotifyState.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AMBULATORY_API UFacialAnimationAnimNotifyState : public UAnimNotifyState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFacialAnimation FacialAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EManagedFacialAnimationPriority FacialAnimationPriority;
    
    UFacialAnimationAnimNotifyState();
};

