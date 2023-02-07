#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AlphaBlend.h"
#include "AblNpcReactAnimRateModifierTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblNpcReactAnimRateModifierTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAlphaBlendOption AlphaBlendOption;
    
public:
    UAblNpcReactAnimRateModifierTask();
};

