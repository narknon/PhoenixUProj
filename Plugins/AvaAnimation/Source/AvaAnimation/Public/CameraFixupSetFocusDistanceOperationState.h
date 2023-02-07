#pragma once
#include "CoreMinimal.h"
#include "CameraFixupOperationState.h"
#include "CameraFixupSetFocusDistanceOperationState.generated.h"

class UTransformProvider;

UCLASS(Blueprintable)
class AVAANIMATION_API UCameraFixupSetFocusDistanceOperationState : public UCameraFixupOperationState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* DistanceTarget;
    
    UCameraFixupSetFocusDistanceOperationState();
};

