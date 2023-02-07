#pragma once
#include "CoreMinimal.h"
#include "Components/RectLightComponent.h"
#include "LightCullingPerLightInterface.h"
#include "LightCullingPerLightSettings.h"
#include "RectLightComponentWithCullingSettings.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LIGHTCULLING_API URectLightComponentWithCullingSettings : public URectLightComponent, public ILightCullingPerLightInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightCullingPerLightSettings LightCullingSettings;
    
    URectLightComponentWithCullingSettings();
    
    // Fix for true pure virtual functions not being implemented
};

