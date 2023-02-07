#pragma once
#include "CoreMinimal.h"
#include "DynamicNoiseTextureColorBase.h"
#include "NoiseParams2D.h"
#include "DynamicNoiseTexture.generated.h"

UCLASS(Blueprintable)
class PERLINNOISE_API UDynamicNoiseTexture : public UDynamicNoiseTextureColorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNoiseParams2D NoiseParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeFactor;
    
    UDynamicNoiseTexture();
};

