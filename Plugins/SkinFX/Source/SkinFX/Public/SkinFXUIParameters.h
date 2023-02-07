#pragma once
#include "CoreMinimal.h"
#include "SkinFXUIScalarParameter.h"
#include "SkinFXUIVectorParameter.h"
#include "SkinFXUIParameters.generated.h"

USTRUCT(BlueprintType)
struct SKINFX_API FSkinFXUIParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSkinFXUIScalarParameter> Scalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSkinFXUIVectorParameter> Vectors;
    
    FSkinFXUIParameters();
};

