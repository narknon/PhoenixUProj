#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapScalarParameter.h"
#include "MaterialSwapTextureParameter.h"
#include "MaterialSwapVectorParameter.h"
#include "MaterialSwapParametersSimple.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapParametersSimple {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaterialSwapScalarParameter> Scalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaterialSwapVectorParameter> Vectors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaterialSwapTextureParameter> Textures;
    
    FMaterialSwapParametersSimple();
};

