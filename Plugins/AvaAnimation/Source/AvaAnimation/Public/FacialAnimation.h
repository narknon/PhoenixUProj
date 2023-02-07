#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FacialAnimation.generated.h"

USTRUCT(BlueprintType)
struct FFacialAnimation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Transition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AnimTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartAtRandomTime;
    
    AVAANIMATION_API FFacialAnimation();
};

