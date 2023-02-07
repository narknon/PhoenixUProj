#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EBasicMobilityMode.h"
#include "AblBranchConditionBasicMobilityMode.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionBasicMobilityMode : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EBasicMobilityMode::Type> BasicMobilityMode;
    
public:
    UAblBranchConditionBasicMobilityMode();
};

