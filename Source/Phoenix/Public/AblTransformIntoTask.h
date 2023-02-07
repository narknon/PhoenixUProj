#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "Templates/SubclassOf.h"
#include "AblTransformIntoTask.generated.h"

class UAblAbility;

UCLASS(Blueprintable, EditInlineNew)
class UAblTransformIntoTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CreatureName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> CreatureSpawnAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetTransformedCreatureToWild;
    
    UAblTransformIntoTask();
};

