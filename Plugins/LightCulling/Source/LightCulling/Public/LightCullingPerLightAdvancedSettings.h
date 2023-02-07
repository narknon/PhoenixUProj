#pragma once
#include "CoreMinimal.h"
#include "LightCullingPerLightAdvancedSettings.generated.h"

USTRUCT(BlueprintType)
struct FLightCullingPerLightAdvancedSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bDisableMoveableCulling: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bDisableTickInterfaceCulling: 1;
    
    LIGHTCULLING_API FLightCullingPerLightAdvancedSettings();
};

