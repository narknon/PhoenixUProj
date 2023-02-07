#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CogGroupEvaluation.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class COGNITION_API UCogGroupEvaluation : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PriorityWeight;
    
    UCogGroupEvaluation();
};

