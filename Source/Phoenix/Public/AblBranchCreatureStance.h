#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "ECreatureStance.h"
#include "AblBranchCreatureStance.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchCreatureStance : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseCurrentStance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ECreatureStance> CreatureStances;
    
public:
    UAblBranchCreatureStance();
};

