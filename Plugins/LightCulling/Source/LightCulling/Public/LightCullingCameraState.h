#pragma once
#include "CoreMinimal.h"
#include "LightCullingCameraState.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct LIGHTCULLING_API FLightCullingCameraState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Player;
    
    FLightCullingCameraState();
};

