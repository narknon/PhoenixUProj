#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EEdgeState.h"
#include "AblBranchConditionEdgeState.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionEdgeState : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<EEdgeState::Type>> EdgeStates;
    
public:
    UAblBranchConditionEdgeState();
};

