#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "UpdateNiagaraFXFloatCurve.generated.h"

USTRUCT(BlueprintType)
struct FUpdateNiagaraFXFloatCurve {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Parameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKillWhenDone;
    
    PHOENIX_API FUpdateNiagaraFXFloatCurve();
};

