#pragma once
#include "CoreMinimal.h"
#include "LightCullingLightPhysicsParent.h"
#include "LightCullingLight.generated.h"

USTRUCT(BlueprintType)
struct LIGHTCULLING_API FLightCullingLight {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLightCullingLightPhysicsParent PhysicsParent;
    
    FLightCullingLight();
};

