#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LEDFadeEffectProperty.generated.h"

USTRUCT(BlueprintType)
struct TOOLSET_API FLEDFadeEffectProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor FadeToRGB;
    
    FLEDFadeEffectProperty();
};

