#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapParametersSimple.h"
#include "MaterialSwapTransformedPosition.h"
#include "MaterialSwapTransformedVector.h"
#include "MaterialSwapParameters.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapParameters : public FMaterialSwapParametersSimple {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaterialSwapTransformedPosition> TransformedPositions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaterialSwapTransformedVector> TransformedVectors;
    
    FMaterialSwapParameters();
};

