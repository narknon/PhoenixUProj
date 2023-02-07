#pragma once
#include "CoreMinimal.h"
#include "WorldFXCascadeSystemParamColor.h"
#include "WorldFXCascadeSystemParamMaterial.h"
#include "WorldFXCascadeSystemParamScalar.h"
#include "WorldFXCascadeSystemParamScalarRand.h"
#include "WorldFXCascadeSystemParamVector.h"
#include "WorldFXCascadeSystemParamVectorRand.h"
#include "WorldFXCascadeSystemParamVectorUnitRand.h"
#include "WorldFXCascadeSystemParams.generated.h"

USTRUCT(BlueprintType)
struct WORLDFX_API FWorldFXCascadeSystemParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWorldFXCascadeSystemParamScalar> Scalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWorldFXCascadeSystemParamScalarRand> ScalarRands;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWorldFXCascadeSystemParamVector> Vectors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWorldFXCascadeSystemParamVectorRand> VectorRands;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWorldFXCascadeSystemParamVectorUnitRand> VectorUnitRands;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWorldFXCascadeSystemParamColor> Colors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWorldFXCascadeSystemParamMaterial> Materials;
    
    FWorldFXCascadeSystemParams();
};

