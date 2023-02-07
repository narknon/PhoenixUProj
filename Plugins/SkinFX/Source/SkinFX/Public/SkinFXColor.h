#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ESkinFXEnvelopeColorMod.h"
#include "SkinFXColorAdvanced.h"
#include "SkinFXMaterialVectorProperty.h"
#include "SkinFXColor.generated.h"

USTRUCT(BlueprintType)
struct FSkinFXColor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXMaterialVectorProperty MaterialParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Color;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkinFXEnvelopeColorMod EnvelopeColorMod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMultiplyByASREnvelope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXColorAdvanced Advanced;
    
    SKINFX_API FSkinFXColor();
};

