#pragma once
#include "CoreMinimal.h"
#include "CachedMIDParameterScalar.h"
#include "CachedMIDParameterVector.h"
#include "CachedMIDParameters.generated.h"

USTRUCT(BlueprintType)
struct AVARENDERTECH_API FCachedMIDParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCachedMIDParameterScalar> Scalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCachedMIDParameterVector> Vectors;
    
    FCachedMIDParameters();
};

