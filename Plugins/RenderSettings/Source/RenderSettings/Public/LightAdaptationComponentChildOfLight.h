#pragma once
#include "CoreMinimal.h"
#include "LightAdaptationComponent.h"
#include "LightAdaptationComponentChildOfLight.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API ULightAdaptationComponentChildOfLight : public ULightAdaptationComponent {
    GENERATED_BODY()
public:
    ULightAdaptationComponentChildOfLight();
};

