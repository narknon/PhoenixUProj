#pragma once
#include "CoreMinimal.h"
#include "CameraStackVolumeInfluence.generated.h"

class UCameraStackBehavior;
class UCameraStackBehaviorInfluenceCrossBlend;
class UObject;

USTRUCT(BlueprintType)
struct FCameraStackVolumeInfluence {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCameraStackBehavior* Behavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCameraStackBehaviorInfluenceCrossBlend* CrossBlendBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCameraStackBehavior* ExistingBehavior;
    
    CAMERASTACK_API FCameraStackVolumeInfluence();
};

