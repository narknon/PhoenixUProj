#pragma once
#include "CoreMinimal.h"
#include "CameraFixupSetPositionMethodState.h"
#include "CameraFixupSetPositionXYZMethodState.generated.h"

class UTransformProvider;

UCLASS(Blueprintable)
class AVAANIMATION_API UCameraFixupSetPositionXYZMethodState : public UCameraFixupSetPositionMethodState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* Target;
    
    UCameraFixupSetPositionXYZMethodState();
};

