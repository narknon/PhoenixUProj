#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblSetVsPhysicsCollisionResolutionEnabledTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblSetVsPhysicsCollisionResolutionEnabledTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
public:
    UAblSetVsPhysicsCollisionResolutionEnabledTask();
};

