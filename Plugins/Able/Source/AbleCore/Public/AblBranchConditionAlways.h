#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchConditionAlways.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblBranchConditionAlways : public UAblBranchCondition {
    GENERATED_BODY()
public:
    UAblBranchConditionAlways();
};

