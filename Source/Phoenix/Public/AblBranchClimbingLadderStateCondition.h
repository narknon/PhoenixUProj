#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EClimbingLadderState.h"
#include "AblBranchClimbingLadderStateCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchClimbingLadderStateCondition : public UAblBranchCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<EClimbingLadderState::Type>> LadderStates;
    
    UAblBranchClimbingLadderStateCondition();
};

