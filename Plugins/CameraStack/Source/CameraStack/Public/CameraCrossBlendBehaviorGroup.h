#pragma once
#include "CoreMinimal.h"
#include "CameraCrossBlendBehaviorGroup.generated.h"

class UCameraStackBehavior;

USTRUCT(BlueprintType)
struct FCameraCrossBlendBehaviorGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UCameraStackBehavior*> Behaviors;
    
    CAMERASTACK_API FCameraCrossBlendBehaviorGroup();
};

