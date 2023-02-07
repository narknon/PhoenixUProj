#pragma once
#include "CoreMinimal.h"
#include "FogDirectionalLight.h"
#include "FogDirectionalLightFollowCamera.generated.h"

UCLASS(Blueprintable)
class EXPHEIGHTFOGVOLUMES_API ADEPRECATED_FogDirectionalLightFollowCamera : public ADEPRECATED_FogDirectionalLight {
    GENERATED_BODY()
public:
    ADEPRECATED_FogDirectionalLightFollowCamera();
};

