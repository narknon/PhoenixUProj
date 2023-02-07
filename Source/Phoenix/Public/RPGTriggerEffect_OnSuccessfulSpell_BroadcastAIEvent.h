#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_BroadcastAIEvent.h"
#include "SocialSemanticIDs.h"
#include "RPGTriggerEffect_OnSuccessfulSpell_BroadcastAIEvent.generated.h"

class AWandTool;

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_OnSuccessfulSpell_BroadcastAIEvent : public URPGTriggerEffect_BroadcastAIEvent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AWandTool* WandTool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckSpellGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<SocialSemanticIDs> RequiredSpellGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRequiresCharacterTarget;
    
public:
    URPGTriggerEffect_OnSuccessfulSpell_BroadcastAIEvent();
};

