#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LEDFadeEffectProperty.h"
#include "LEDFadeEffect.generated.h"

UCLASS(Blueprintable)
class TOOLSET_API ULEDFadeEffect : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLEDFadeEffectProperty> FadeEffectProperties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Loop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SetOnEnd;
    
    ULEDFadeEffect();
};

