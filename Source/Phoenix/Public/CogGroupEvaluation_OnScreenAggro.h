#pragma once
#include "CoreMinimal.h"
#include "CogGroupEvaluation.h"
#include "CogGroupEvaluation_OnScreenAggro.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCogGroupEvaluation_OnScreenAggro : public UCogGroupEvaluation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScreenBorder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OffscreenMultiplier;
    
    UCogGroupEvaluation_OnScreenAggro();
};

