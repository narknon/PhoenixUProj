#pragma once
#include "CoreMinimal.h"
#include "Components/PointLightComponent.h"
#include "LightCullingPerLightInterface.h"
#include "LightCullingPerLightSettings.h"
#include "PointLightComponentWithCullingSettings.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LIGHTCULLING_API UPointLightComponentWithCullingSettings : public UPointLightComponent, public ILightCullingPerLightInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightCullingPerLightSettings LightCullingSettings;
    
    UPointLightComponentWithCullingSettings();
    
    // Fix for true pure virtual functions not being implemented
};

