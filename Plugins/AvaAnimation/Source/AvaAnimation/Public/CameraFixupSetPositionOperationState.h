#pragma once
#include "CoreMinimal.h"
#include "CameraFixupOperationState.h"
#include "CameraFixupSetPositionOperationState.generated.h"

class UCameraFixupSetPositionMethodState;

UCLASS(Blueprintable)
class AVAANIMATION_API UCameraFixupSetPositionOperationState : public UCameraFixupOperationState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCameraFixupSetPositionMethodState* MethodState;
    
    UCameraFixupSetPositionOperationState();
};

