#pragma once
#include "CoreMinimal.h"
#include "EWorldFXDistanceType.h"
#include "WorldFXCullDistance.generated.h"

USTRUCT(BlueprintType)
struct FWorldFXCullDistance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWorldFXDistanceType DistanceType;
    
    WORLDFX_API FWorldFXCullDistance();
};

