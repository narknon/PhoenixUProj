#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblSuperSlamSpawnPhysicsActorScratchpad.generated.h"

class AStaticMeshActor;

UCLASS(Blueprintable, NonTransient)
class UAblSuperSlamSpawnPhysicsActorScratchpad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AStaticMeshActor*> Actors;
    
    UAblSuperSlamSpawnPhysicsActorScratchpad();
};

