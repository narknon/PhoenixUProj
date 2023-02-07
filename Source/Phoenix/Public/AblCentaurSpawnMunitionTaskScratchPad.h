#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblCentaurSpawnMunitionTaskScratchPad.generated.h"

class AActor;

UCLASS(Blueprintable, NonTransient)
class UAblCentaurSpawnMunitionTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* EquipArrowActor;
    
    UAblCentaurSpawnMunitionTaskScratchPad();
};

