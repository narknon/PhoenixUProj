#pragma once
#include "CoreMinimal.h"
#include "Engine/Scene.h"
#include "AnimatedLightExtraCachedLightSettings.generated.h"

USTRUCT(BlueprintType)
struct ANIMATEDLIGHTS_API FAnimatedLightExtraCachedLightSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELightUnits IntensityUnits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CosHalfConeAngle;
    
    FAnimatedLightExtraCachedLightSettings();
};

