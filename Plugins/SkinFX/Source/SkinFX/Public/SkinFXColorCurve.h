#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveLinearColor.h"
#include "ESkinFXEnvelopeColorMod.h"
#include "SkinFXColorAdvanced.h"
#include "SkinFXMaterialVectorProperty.h"
#include "SkinFXColorCurve.generated.h"

USTRUCT(BlueprintType)
struct FSkinFXColorCurve {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXMaterialVectorProperty MaterialParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeCurveLinearColor ColorCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStretchToEnvelope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLoop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkinFXEnvelopeColorMod EnvelopeColorMod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMultiplyByASREnvelope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXColorAdvanced Advanced;
    
    SKINFX_API FSkinFXColorCurve();
};

