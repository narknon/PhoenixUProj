#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_BroadcastAIEvent.h"
#include "RPG_TriggerEffect_OnCharacterDeath_BroadcastAIEvent.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPG_TriggerEffect_OnCharacterDeath_BroadcastAIEvent : public URPGTriggerEffect_BroadcastAIEvent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNeedToBeDeathInstigator;
    
public:
    URPG_TriggerEffect_OnCharacterDeath_BroadcastAIEvent();
};

