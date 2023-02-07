#pragma once
#include "CoreMinimal.h"
#include "SkinFXEnvelopeEase.h"
#include "SkinFXEnvelopeReshaper.generated.h"

USTRUCT(BlueprintType)
struct FSkinFXEnvelopeReshaper {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXEnvelopeEase Shaping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReshape;
    
    SKINFX_API FSkinFXEnvelopeReshaper();
};

