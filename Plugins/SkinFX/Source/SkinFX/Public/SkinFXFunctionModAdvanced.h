#pragma once
#include "CoreMinimal.h"
#include "SkinFXEnvelopeReshaper.h"
#include "SkinFXFunctionModAdvanced.generated.h"

USTRUCT(BlueprintType)
struct FSkinFXFunctionModAdvanced {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXEnvelopeReshaper ReshapeASREnvelope;
    
    SKINFX_API FSkinFXFunctionModAdvanced();
};

