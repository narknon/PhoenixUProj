#pragma once
#include "CoreMinimal.h"
#include "AvaStreamingLevelVolumeComponentBase.h"
#include "AvaShellVolumeComponent.generated.h"

class ATriggerBox;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAvaShellVolumeComponent : public UAvaStreamingLevelVolumeComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ATriggerBox* VolumeToIntersectAgainsStreamingVolumes;
    
    UAvaShellVolumeComponent();
};

