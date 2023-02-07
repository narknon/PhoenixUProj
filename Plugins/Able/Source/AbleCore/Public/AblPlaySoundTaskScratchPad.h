#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblPlaySoundTaskScratchPad.generated.h"

class UAudioComponent;

UCLASS(Blueprintable, NonTransient)
class UAblPlaySoundTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UAudioComponent>> AttachedSounds;
    
    UAblPlaySoundTaskScratchPad();
};

