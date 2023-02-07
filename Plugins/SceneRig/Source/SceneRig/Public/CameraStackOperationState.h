#pragma once
#include "CoreMinimal.h"
#include "CameraStackOperationState.generated.h"

class UCameraStackOperationBase;
class UCameraStackOperationScratchData;

USTRUCT(BlueprintType)
struct FCameraStackOperationState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCameraStackOperationBase* Operation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCameraStackOperationScratchData* ScratchData;
    
    SCENERIG_API FCameraStackOperationState();
};

