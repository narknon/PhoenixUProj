#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "Templates/SubclassOf.h"
#include "AblBranchConditionCognitionTarget.generated.h"

class AActor;
class UAISense_Cognition;

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionCognitionTarget : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAISense_Cognition> CognitionSense;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> MatchActorType;
    
public:
    UAblBranchConditionCognitionTarget();
};

