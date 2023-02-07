#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EStationState.h"
#include "AblBranchConditionStationState.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionStationState : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EStationState::Type> StationState;
    
public:
    UAblBranchConditionStationState();
};

