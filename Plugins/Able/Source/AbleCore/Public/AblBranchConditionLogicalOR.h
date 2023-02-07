#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchConditionLogicalOR.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblBranchConditionLogicalOR : public UAblBranchCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblBranchCondition*> Conditions;
    
    UAblBranchConditionLogicalOR();
};

