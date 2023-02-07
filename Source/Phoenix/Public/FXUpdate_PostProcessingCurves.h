#pragma once
#include "CoreMinimal.h"
#include "FXUpdate_Tick.h"
#include "PostProcessingFXCurveSet.h"
#include "FXUpdate_PostProcessingCurves.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXUpdate_PostProcessingCurves : public UFXUpdate_Tick {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPostProcessingFXCurveSet Curves;
    
    UFXUpdate_PostProcessingCurves();
};

