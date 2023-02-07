#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EGlobalLightRigModParam.h"
#include "ELightParameterSmoothingTimeBase.h"
#include "ELightParameterSmoothingTimeSource.h"
#include "ELightParameterTimeBlendInput.h"
#include "LightParameterSmoothing.generated.h"

class UCurveFloat;

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class DAYNIGHT_API ULightParameterSmoothing : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EGlobalLightRigModParam> ModParamSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELightParameterSmoothingTimeSource TimeSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELightParameterSmoothingTimeBase TimeBase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* TimeBlendCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELightParameterTimeBlendInput TimeBlendCurveInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    ULightParameterSmoothing();
};

