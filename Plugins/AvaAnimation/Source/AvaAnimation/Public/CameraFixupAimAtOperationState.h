#pragma once
#include "CoreMinimal.h"
#include "CameraFixupOperationState.h"
#include "CameraFixupAimAtOperationState.generated.h"

class UTransformProvider;

UCLASS(Blueprintable)
class AVAANIMATION_API UCameraFixupAimAtOperationState : public UCameraFixupOperationState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* AimTarget;
    
    UCameraFixupAimAtOperationState();
};

