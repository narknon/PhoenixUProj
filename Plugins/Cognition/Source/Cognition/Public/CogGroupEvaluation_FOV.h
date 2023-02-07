#pragma once
#include "CoreMinimal.h"
#include "CogGroupEvaluation.h"
#include "CogGroupEvaluation_FOV.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class COGNITION_API UCogGroupEvaluation_FOV : public UCogGroupEvaluation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoAcceptIfFootprintOverlap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseTargetFootprintForFOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreForSticky;
    
    UCogGroupEvaluation_FOV();
};

