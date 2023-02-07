#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesAudioStateGroupNameBase.h"
#include "LerpVolumesAudioStateGroupName.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesAudioStateGroupName : public FLerpVolumesAudioStateGroupNameBase {
    GENERATED_BODY()
public:
    LERPVOLUMES_API FLerpVolumesAudioStateGroupName();
};

