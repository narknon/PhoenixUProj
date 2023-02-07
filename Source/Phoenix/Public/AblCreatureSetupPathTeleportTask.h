#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblCreatureSetupPathTeleportTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblCreatureSetupPathTeleportTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TeleportChanceOnStart;
    
    UAblCreatureSetupPathTeleportTask();
};

