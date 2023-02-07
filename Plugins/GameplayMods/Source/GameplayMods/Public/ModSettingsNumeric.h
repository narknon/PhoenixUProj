#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "EInputModType.h"
#include "EPropModCalculationType.h"
#include "ETimeBasedEffectType.h"
#include "ModSettingsNumeric.generated.h"

USTRUCT(BlueprintType)
struct FModSettingsNumeric {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPropModCalculationType CalculationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETimeBasedEffectType TimeBasedEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInputModType ExternalInputEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve TimeCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve InputCurve;
    
    GAMEPLAYMODS_API FModSettingsNumeric();
};

