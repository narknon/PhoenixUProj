#pragma once
#include "CoreMinimal.h"
#include "CameraStackAnimationRequest.generated.h"

class UAnimSequence;

USTRUCT(BlueprintType)
struct CAMERASTACK_API FCameraStackAnimationRequest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequence* AnimSequence;
    
    FCameraStackAnimationRequest();
};

