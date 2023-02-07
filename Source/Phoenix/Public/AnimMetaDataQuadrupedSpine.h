#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimMetaData.h"
#include "Curves/CurveFloat.h"
#include "AnimMetaDataQuadrupedSpine.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UAnimMetaDataQuadrupedSpine : public UAnimMetaData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableSpineBending;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve SpineStartCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve SpineEndCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve TurnRateStartCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve TurnRateEndCurve;
    
    UAnimMetaDataQuadrupedSpine();
};

