#pragma once
#include "CoreMinimal.h"
#include "CogGroupEvaluation.h"
#include "CogGroupEvaluation_Distance.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class COGNITION_API UCogGroupEvaluation_Distance : public UCogGroupEvaluation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NearDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FarDistance;
    
    UCogGroupEvaluation_Distance();
};

