#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesName.h"
#include "LerpVolumesVectorName.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesVectorName : public FLerpVolumesName {
    GENERATED_BODY()
public:
    LERPVOLUMES_API FLerpVolumesVectorName();
};

