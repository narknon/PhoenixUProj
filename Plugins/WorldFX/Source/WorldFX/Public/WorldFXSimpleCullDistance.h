#pragma once
#include "CoreMinimal.h"
#include "EWorldFXSimpleDistanceType.h"
#include "WorldFXSimpleCullDistance.generated.h"

USTRUCT(BlueprintType)
struct FWorldFXSimpleCullDistance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWorldFXSimpleDistanceType DistanceType;
    
    WORLDFX_API FWorldFXSimpleCullDistance();
};

