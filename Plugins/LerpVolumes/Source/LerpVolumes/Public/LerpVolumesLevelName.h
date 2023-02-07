#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesName.h"
#include "LerpVolumesLevelName.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesLevelName : public FLerpVolumesName {
    GENERATED_BODY()
public:
    LERPVOLUMES_API FLerpVolumesLevelName();
};

