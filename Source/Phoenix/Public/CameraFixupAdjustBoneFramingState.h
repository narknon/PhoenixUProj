#pragma once
#include "CoreMinimal.h"
#include "CameraFixupOperationState.h"
#include "CameraFixupAdjustBoneFramingState.generated.h"

class UTransformProvider;

UCLASS(Blueprintable)
class UCameraFixupAdjustBoneFramingState : public UCameraFixupOperationState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* TargetBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* ReferenceBone;
    
    UCameraFixupAdjustBoneFramingState();
};

