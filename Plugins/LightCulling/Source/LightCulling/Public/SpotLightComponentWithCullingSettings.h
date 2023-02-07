#pragma once
#include "CoreMinimal.h"
#include "Components/SpotLightComponent.h"
#include "LightCullingPerLightInterface.h"
#include "LightCullingPerLightSettings.h"
#include "SpotLightComponentWithCullingSettings.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LIGHTCULLING_API USpotLightComponentWithCullingSettings : public USpotLightComponent, public ILightCullingPerLightInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightCullingPerLightSettings LightCullingSettings;
    
    USpotLightComponentWithCullingSettings();
    
    // Fix for true pure virtual functions not being implemented
};

