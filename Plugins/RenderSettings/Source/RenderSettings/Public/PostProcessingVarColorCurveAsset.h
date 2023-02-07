#pragma once
#include "CoreMinimal.h"
#include "PostProcessingVarColorBase.h"
#include "PostProcessingVarColorCurveAsset.generated.h"

class UCurveLinearColor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API UPostProcessingVarColorCurveAsset : public UPostProcessingVarColorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveLinearColor* Curve;
    
    UPostProcessingVarColorCurveAsset();
};

