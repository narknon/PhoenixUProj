#pragma once
#include "CoreMinimal.h"
#include "AblTaskConditionScratchpad.h"
#include "AblTaskConditionScratchpad_OppugnoProxy.generated.h"

class AActor;
class ATool;
class AWorldObject;

UCLASS(Blueprintable, NonTransient)
class UAblTaskConditionScratchpad_OppugnoProxy : public UAblTaskConditionScratchpad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AWorldObject* instancedProxy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* EnemyOwner;
    
    UAblTaskConditionScratchpad_OppugnoProxy();
    UFUNCTION(BlueprintCallable)
    void OnActiveSpellToolChanged(ATool* ActivatedSpell, ATool* DeactivatedSpell);
    
};

