#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblFlyToLocationTaskBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAblFlyToLocationTaskBase : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UAblFlyToLocationTaskBase();
};

