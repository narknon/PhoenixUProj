#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "GameplayTagContainer.h"
#include "EFacialEmotion.h"
#include "EManagedFacialEmotionPriority.h"
#include "FacialEmotionAnimNotifyState.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AMBULATORY_API UFacialEmotionAnimNotifyState : public UAnimNotifyState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFacialEmotion FacialEmotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TransitionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EManagedFacialEmotionPriority FacialEmotionPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AnimTags;
    
    UFacialEmotionAnimNotifyState();
};

