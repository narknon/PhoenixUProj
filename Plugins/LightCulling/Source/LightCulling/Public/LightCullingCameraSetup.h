#pragma once
#include "CoreMinimal.h"
#include "LightCullingCameraSetup.generated.h"

USTRUCT(BlueprintType)
struct FLightCullingCameraSetup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerDistanceBiasMeters;
    
    LIGHTCULLING_API FLightCullingCameraSetup();
};

