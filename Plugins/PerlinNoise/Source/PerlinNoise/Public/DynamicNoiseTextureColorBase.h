#pragma once
#include "CoreMinimal.h"
#include "DynamicNoiseTextureBase.h"
#include "DynamicNoiseTextureColorBase.generated.h"

class UCurveLinearColor;

UCLASS(Abstract, Blueprintable)
class PERLINNOISE_API UDynamicNoiseTextureColorBase : public UDynamicNoiseTextureBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveLinearColor* Palette;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWantMask;
    
    UDynamicNoiseTextureColorBase();
};

