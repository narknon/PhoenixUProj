#pragma once
#include "CoreMinimal.h"
#include "AnimationRequestLayerReference.h"
#include "GameplayTagContainer.h"
#include "DialogLineRule_CameraAnimation.generated.h"

USTRUCT(BlueprintType)
struct FDialogLineRule_CameraAnimation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationRequestLayerReference Layer;
    
    PHOENIX_API FDialogLineRule_CameraAnimation();
};

