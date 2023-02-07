#pragma once
#include "CoreMinimal.h"
#include "SkinFXMaterialScalarProperty.h"
#include "SkinFXScalarAdvanced.h"
#include "SkinFXScalar.generated.h"

USTRUCT(BlueprintType)
struct FSkinFXScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXMaterialScalarProperty MaterialParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Scalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMultiplyByASREnvelope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXScalarAdvanced Advanced;
    
    SKINFX_API FSkinFXScalar();
};

