#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesAudioStateGroupNameBase.h"
#include "LerpVolumesAudioStateGroupLocation.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesAudioStateGroupLocation : public FLerpVolumesAudioStateGroupNameBase {
    GENERATED_BODY()
public:
    LERPVOLUMES_API FLerpVolumesAudioStateGroupLocation();
};

