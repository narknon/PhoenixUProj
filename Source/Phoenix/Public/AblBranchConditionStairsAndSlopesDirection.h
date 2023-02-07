#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EStairsDirectionState.h"
#include "AblBranchConditionStairsAndSlopesDirection.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionStairsAndSlopesDirection : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EStairsDirectionState::Type> StairsDirection;
    
public:
    UAblBranchConditionStairsAndSlopesDirection();
};

