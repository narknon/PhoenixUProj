#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblSpawnActorTaskScratchPad.generated.h"

class AActor;

UCLASS(Blueprintable, NonTransient)
class UAblSpawnActorTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> SpawnedActor;
    
    UAblSpawnActorTaskScratchPad();
};

