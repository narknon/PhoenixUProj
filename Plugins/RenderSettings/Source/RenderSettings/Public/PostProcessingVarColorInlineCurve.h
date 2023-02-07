#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveLinearColor.h"
#include "PostProcessingVarColorBase.h"
#include "PostProcessingVarColorInlineCurve.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API UPostProcessingVarColorInlineCurve : public UPostProcessingVarColorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeCurveLinearColor Value;
    
    UPostProcessingVarColorInlineCurve();
};

