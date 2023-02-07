#pragma once
#include "CoreMinimal.h"
#include "CogGroupEvaluation.h"
#include "CogGroupEvaluation_FOVSticky.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCogGroupEvaluation_FOVSticky : public UCogGroupEvaluation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoAcceptIfFootprintOverlap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseTargetFootprintForFOV;
    
    UCogGroupEvaluation_FOVSticky();
};

