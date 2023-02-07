#pragma once
#include "CoreMinimal.h"
#include "AblConditionalBranchTaskBase.h"
#include "Templates/SubclassOf.h"
#include "AblConditionalBranchTask.generated.h"

class UAblAbility;

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblConditionalBranchTask : public UAblConditionalBranchTaskBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> BranchAbilityClass;
    
public:
    UAblConditionalBranchTask();
};

