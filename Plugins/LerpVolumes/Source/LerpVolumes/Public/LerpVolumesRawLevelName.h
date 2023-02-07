#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesName.h"
#include "LerpVolumesRawLevelName.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesRawLevelName : public FLerpVolumesName {
    GENERATED_BODY()
public:
    LERPVOLUMES_API FLerpVolumesRawLevelName();
};

