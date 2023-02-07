#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveLinearColor.h"
#include "UpdateNiagaraFXColorCurve.generated.h"

USTRUCT(BlueprintType)
struct FUpdateNiagaraFXColorCurve {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Parameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeCurveLinearColor Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKillWhenDone;
    
    PHOENIX_API FUpdateNiagaraFXColorCurve();
};

