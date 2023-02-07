#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "CameraStackBehavior.h"
#include "CameraStackBehaviorCollisionSweepVertical.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorCollisionSweepVertical : public UCameraStackBehavior {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProbeSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECollisionChannel> ProbeChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SweepStartHeight;
    
    UCameraStackBehaviorCollisionSweepVertical();
};

