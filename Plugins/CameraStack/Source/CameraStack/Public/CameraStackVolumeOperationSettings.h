#pragma once
#include "CoreMinimal.h"
#include "ECameraStackVolumeOperation.h"
#include "Templates/SubclassOf.h"
#include "CameraStackVolumeOperationSettings.generated.h"

class UCameraStackBehavior;

USTRUCT(BlueprintType)
struct FCameraStackVolumeOperationSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraStackBehavior* BehaviorToAdd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraStackVolumeOperation Operation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraStackBehavior> ExistingBehaviorClass;
    
    CAMERASTACK_API FCameraStackVolumeOperationSettings();
};

