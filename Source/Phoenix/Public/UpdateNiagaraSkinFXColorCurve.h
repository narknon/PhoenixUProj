#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveLinearColor.h"
#include "UpdateNiagaraSkinFXColorCurve.generated.h"

USTRUCT(BlueprintType)
struct FUpdateNiagaraSkinFXColorCurve {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NiagaraParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SkinFXParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeCurveLinearColor Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKillWhenDone;
    
    PHOENIX_API FUpdateNiagaraSkinFXColorCurve();
};

