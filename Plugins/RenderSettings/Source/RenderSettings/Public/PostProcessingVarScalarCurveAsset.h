#pragma once
#include "CoreMinimal.h"
#include "PostProcessingVarScalarBase.h"
#include "PostProcessingVarScalarCurveAsset.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API UPostProcessingVarScalarCurveAsset : public UPostProcessingVarScalarBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* Curve;
    
    UPostProcessingVarScalarCurveAsset();
};

