#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CreatureLookAtTargetEvaluationConfig.generated.h"

class UCreatureLookAtTargetEvaluation;

UCLASS(Blueprintable)
class UCreatureLookAtTargetEvaluationConfig : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThresholdScore;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCreatureLookAtTargetEvaluation*> EvaluationArray;
    
    UCreatureLookAtTargetEvaluationConfig();
};

