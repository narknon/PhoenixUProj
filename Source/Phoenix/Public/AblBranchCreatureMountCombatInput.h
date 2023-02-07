#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "AblBranchCreatureMountCombatInput.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchCreatureMountCombatInput : public UAblTaskCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bChargeActive;
    
public:
    UAblBranchCreatureMountCombatInput();
};

