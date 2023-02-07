#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AnimRequestProvider.h"
#include "AnimationTrack.h"
#include "AnimRequest_FacialEmotion.generated.h"

UCLASS(Blueprintable)
class AVAANIMATION_API UAnimRequest_FacialEmotion : public UObject, public IAnimRequestProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationTrack FacialEmotionTrackA;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationTrack FacialEmotionTrackB;
    
    UAnimRequest_FacialEmotion();
    
    // Fix for true pure virtual functions not being implemented
};

