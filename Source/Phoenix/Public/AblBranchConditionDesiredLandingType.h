#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "ECreatureLandingType.h"
#include "AblBranchConditionDesiredLandingType.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionDesiredLandingType : public UAblBranchCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ECreatureLandingType> LandingTypes;
    
    UAblBranchConditionDesiredLandingType();
};

