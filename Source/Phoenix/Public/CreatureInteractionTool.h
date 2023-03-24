#pragma once
#include "CoreMinimal.h"
#include "ETargetSpeedMode.h"
#include "InventoryItemTool.h"
#include "CreatureInteractionTool.generated.h"

class ABiped_Player;
class ACreature_Character;

UCLASS(Blueprintable)
class ACreatureInteractionTool : public AInventoryItemTool {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACreature_Character* TargetCreature;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ABiped_Player* Player;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ETargetSpeedMode::Type> InteractingSpeedMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InteractRange;
    
public:
    ACreatureInteractionTool(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable)
    void RequestInteractionEnd();
    
    UFUNCTION(BlueprintCallable)
    void RemoveLookAtTarget();
    
    UFUNCTION(BlueprintCallable)
    void RemoveFaceTarget();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTickInteraction(float DeltaSeconds);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInteractionStarted();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInteractionEndRequested();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInteractionEnded();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetInteractionEndRequested() const;
    
    UFUNCTION(BlueprintCallable)
    void EnableInteractionCamera();
    
    UFUNCTION(BlueprintCallable)
    void DisableInteractionCamera();
    
    UFUNCTION(BlueprintCallable)
    void AllowInteractionEnd();
    
    UFUNCTION(BlueprintCallable)
    void AddLookAtTarget();
    
    UFUNCTION(BlueprintCallable)
    void AddFaceTarget();
    
};

