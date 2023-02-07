#pragma once
#include "CoreMinimal.h"
#include "CameraFixupOperationState.h"
#include "CameraFixupNoiseOperationState.generated.h"

class UCameraFixupNoiseOperations;

UCLASS(Blueprintable)
class AVAANIMATION_API UCameraFixupNoiseOperationState : public UCameraFixupOperationState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCameraFixupNoiseOperations* CameraFixupNoiseOperations;
    
    UCameraFixupNoiseOperationState();
};

