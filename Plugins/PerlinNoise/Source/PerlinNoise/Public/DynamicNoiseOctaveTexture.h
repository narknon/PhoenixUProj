#pragma once
#include "CoreMinimal.h"
#include "DynamicNoiseTextureColorBase.h"
#include "OctaveNoiseParams.h"
#include "DynamicNoiseOctaveTexture.generated.h"

UCLASS(Blueprintable)
class PERLINNOISE_API UDynamicNoiseOctaveTexture : public UDynamicNoiseTextureColorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOctaveNoiseParams NoiseParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeFactor;
    
    UDynamicNoiseOctaveTexture();
};

