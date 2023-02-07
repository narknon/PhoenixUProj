#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "UpdateNiagaraSkinFXFloatCurve.generated.h"

USTRUCT(BlueprintType)
struct FUpdateNiagaraSkinFXFloatCurve {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NiagaraParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SkinFXParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKillWhenDone;
    
    PHOENIX_API FUpdateNiagaraSkinFXFloatCurve();
};

