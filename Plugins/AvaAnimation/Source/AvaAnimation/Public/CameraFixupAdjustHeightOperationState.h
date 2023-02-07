#pragma once
#include "CoreMinimal.h"
#include "CameraFixupOperationState.h"
#include "CameraFixupAdjustHeightOperationState.generated.h"

class UTransformProvider;

UCLASS(Blueprintable)
class AVAANIMATION_API UCameraFixupAdjustHeightOperationState : public UCameraFixupOperationState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* HeightTarget;
    
    UCameraFixupAdjustHeightOperationState();
};

