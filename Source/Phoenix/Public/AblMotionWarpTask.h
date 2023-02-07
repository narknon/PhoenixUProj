#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblMotionWarpTask.generated.h"

class UAblTaskCondition;
class UAvaMotionWarpingModifierConfig;

UCLASS(Blueprintable, EditInlineNew)
class UAblMotionWarpTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAvaMotionWarpingModifierConfig* RootMotionModifierConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblTaskCondition*> Conditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMustPassAllConditions;
    
public:
    UAblMotionWarpTask();
};

