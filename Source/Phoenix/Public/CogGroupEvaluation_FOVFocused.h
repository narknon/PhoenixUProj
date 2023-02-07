#pragma once
#include "CoreMinimal.h"
#include "CogGroupEvaluation_FOV.h"
#include "CogGroupEvaluation_FOVFocused.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCogGroupEvaluation_FOVFocused : public UCogGroupEvaluation_FOV {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NotFocusedMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScreenBorder;
    
    UCogGroupEvaluation_FOVFocused();
};

