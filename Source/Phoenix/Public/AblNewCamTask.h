#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "CameraProperties.h"
#include "LookAtType.h"
#include "AblNewCamTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblNewCamTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCameraProperties> camProperties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float customCameraWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    LookAtType LookAtTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool alwaysLookAtTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SequentiallyPlayAllCameras;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Disable;
    
public:
    UAblNewCamTask();
};

