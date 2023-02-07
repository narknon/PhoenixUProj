#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblCreatureMoveToDesiredDirectionOverrideTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblCreatureMoveToDesiredDirectionOverrideTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TargetActorOrLocationKeyName;
    
    UAblCreatureMoveToDesiredDirectionOverrideTask();
};

