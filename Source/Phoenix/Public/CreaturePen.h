#pragma once
#include "CoreMinimal.h"
#include "TransfigurationObjectBase.h"
#include "CreaturePen.generated.h"

class AActor;
class ATriggerBase;
class UCreatureState;

UCLASS(Blueprintable)
class PHOENIX_API ACreaturePen : public ATransfigurationObjectBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ATriggerBase* CachedWalkOutTrigger;
    
    ACreaturePen();
    UFUNCTION(BlueprintCallable)
    void UpdateCallout();
    
    UFUNCTION(BlueprintCallable)
    void OnDressingReady();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCreatureSpawned(UCreatureState* CreatureState, AActor* CreatureActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBreedingStarted(UCreatureState* OffspringState, UCreatureState* MotherState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBreedingFinished();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsReadyToSlotCreature() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOccupied() const;
    
};

