#pragma once
#include "CoreMinimal.h"
#include "Engine/Light.h"
#include "SpotLightWithCullingSettings.generated.h"

class USpotLightComponentWithCullingSettings;

UCLASS(Blueprintable)
class LIGHTCULLING_API ASpotLightWithCullingSettings : public ALight {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpotLightComponentWithCullingSettings* SpotLightComponent;
    
    ASpotLightWithCullingSettings();
    UFUNCTION(BlueprintCallable)
    void Copy();
    
};

