#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "UObject/NoExportTypes.h"
#include "AblBranchConditionPhase.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionPhase : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector2D> PhaseRanges;
    
public:
    UAblBranchConditionPhase();
};

