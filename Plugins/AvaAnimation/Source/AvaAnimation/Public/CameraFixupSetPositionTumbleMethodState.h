#pragma once
#include "CoreMinimal.h"
#include "CameraFixupSetPositionMethodState.h"
#include "CameraFixupSetPositionTumbleMethodState.generated.h"

class UTransformProvider;

UCLASS(Blueprintable)
class AVAANIMATION_API UCameraFixupSetPositionTumbleMethodState : public UCameraFixupSetPositionMethodState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* Target;
    
    UCameraFixupSetPositionTumbleMethodState();
};

