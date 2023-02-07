#pragma once
#include "CoreMinimal.h"
#include "Engine/Light.h"
#include "FogDirectionalLight.generated.h"

UCLASS(Blueprintable, Deprecated, NotPlaceable)
class EXPHEIGHTFOGVOLUMES_API ADEPRECATED_FogDirectionalLight : public ALight {
    GENERATED_BODY()
public:
    ADEPRECATED_FogDirectionalLight();
};

