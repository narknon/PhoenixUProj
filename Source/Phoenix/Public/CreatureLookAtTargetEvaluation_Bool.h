#pragma once
#include "CoreMinimal.h"
#include "CreatureLookAtTargetEvaluation.h"
#include "CreatureLookAtTargetEvaluation_Bool.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UCreatureLookAtTargetEvaluation_Bool : public UCreatureLookAtTargetEvaluation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Multiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInverse;
    
    UCreatureLookAtTargetEvaluation_Bool();
};

