#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "Templates/SubclassOf.h"
#include "AblTransformIntoNoDeathTask.generated.h"

class UAblAbility;

UCLASS(Blueprintable, EditInlineNew)
class UAblTransformIntoNoDeathTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CreatureName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> CreatureSpawnAbility;
    
    UAblTransformIntoNoDeathTask();
};

