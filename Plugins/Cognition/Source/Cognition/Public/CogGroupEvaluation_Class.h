#pragma once
#include "CoreMinimal.h"
#include "CogGroupEvaluation.h"
#include "CogGroupEvaluation_Class.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class COGNITION_API UCogGroupEvaluation_Class : public UCogGroupEvaluation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UClass*> IncludeClasses;
    
    UCogGroupEvaluation_Class();
};

