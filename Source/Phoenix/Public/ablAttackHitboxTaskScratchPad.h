#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "ablAttackHitboxTaskScratchPad.generated.h"

class AMunitionType_Hitbox;

UCLASS(Blueprintable, NonTransient)
class UablAttackHitboxTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AMunitionType_Hitbox* MunitionInstance;
    
    UablAttackHitboxTaskScratchPad();
};

