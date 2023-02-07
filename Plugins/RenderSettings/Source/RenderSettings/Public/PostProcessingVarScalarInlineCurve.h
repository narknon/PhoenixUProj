#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "PostProcessingVarScalarBase.h"
#include "PostProcessingVarScalarInlineCurve.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API UPostProcessingVarScalarInlineCurve : public UPostProcessingVarScalarBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve Value;
    
    UPostProcessingVarScalarInlineCurve();
};

