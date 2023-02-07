#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogParameters.h"
#include "GlobalLightingBlendableBase.h"
#include "GlobalLightingBlendableWeatherFog.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UGlobalLightingBlendableWeatherFog : public UGlobalLightingBlendableBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogParameters FogParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseEye;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bValid;
    
    UGlobalLightingBlendableWeatherFog();
};

