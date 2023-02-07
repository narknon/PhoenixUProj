#pragma once
#include "CoreMinimal.h"
#include "SkinFXEnvelopeReshaper.h"
#include "SkinFXNoiseFunctionModAdvanced.generated.h"

USTRUCT(BlueprintType)
struct FSkinFXNoiseFunctionModAdvanced {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXEnvelopeReshaper ReshapeASREnvelope;
    
    SKINFX_API FSkinFXNoiseFunctionModAdvanced();
};

