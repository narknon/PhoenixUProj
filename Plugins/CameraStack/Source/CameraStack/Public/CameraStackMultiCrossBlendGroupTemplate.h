#pragma once
#include "CoreMinimal.h"
#include "CameraStackMultiCrossBlendGroupTemplate.generated.h"

class UCameraStackBehavior;

USTRUCT(BlueprintType)
struct FCameraStackMultiCrossBlendGroupTemplate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCameraStackBehavior*> BehaviorTemplates;
    
    CAMERASTACK_API FCameraStackMultiCrossBlendGroupTemplate();
};

