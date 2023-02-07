#pragma once
#include "CoreMinimal.h"
#include "SkinFXMaterialScalarProperty.h"
#include "SkinFXUIScalarParameter.generated.h"

USTRUCT(BlueprintType)
struct FSkinFXUIScalarParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXMaterialScalarProperty Parameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    SKINFX_API FSkinFXUIScalarParameter();
};

