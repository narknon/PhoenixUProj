#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AnimRequestProvider.h"
#include "AnimationTrack.h"
#include "AnimRequest_Dialogue.generated.h"

UCLASS(Blueprintable)
class AVAANIMATION_API UAnimRequest_Dialogue : public UObject, public IAnimRequestProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationTrack FacialDialogueMouthOnlyTrack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationTrack FacialDialogueFaceOnlyTrack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationTrack FacialDialogueHeadOnlyTrack;
    
    UAnimRequest_Dialogue();
    
    // Fix for true pure virtual functions not being implemented
};

