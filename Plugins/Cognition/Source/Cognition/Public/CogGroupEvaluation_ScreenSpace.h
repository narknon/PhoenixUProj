#pragma once
#include "CoreMinimal.h"
#include "CogGroupEvaluation.h"
#include "CogGroupEvaluation_ScreenSpace.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class COGNITION_API UCogGroupEvaluation_ScreenSpace : public UCogGroupEvaluation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScreenDistance;
    
    UCogGroupEvaluation_ScreenSpace();
};

