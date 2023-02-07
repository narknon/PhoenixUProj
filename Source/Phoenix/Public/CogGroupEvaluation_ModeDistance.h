#pragma once
#include "CoreMinimal.h"
#include "CogGroupEvaluation_Distance.h"
#include "CogGroupEvaluation_ModeDistance.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCogGroupEvaluation_ModeDistance : public UCogGroupEvaluation_Distance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PriorityNearDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PriorityFarDistance;
    
    UCogGroupEvaluation_ModeDistance();
};

