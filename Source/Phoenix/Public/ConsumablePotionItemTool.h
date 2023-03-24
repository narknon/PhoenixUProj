#pragma once
#include "CoreMinimal.h"
#include "InventoryItemTool.h"
#include "Templates/SubclassOf.h"
#include "ConsumablePotionItemTool.generated.h"

class APotionBottlePhysics;
class UNiagaraComponent;
class UNiagaraSystem;
class UParticleSystem;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class AConsumablePotionItemTool : public AInventoryItemTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* PotionMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* LiquidParticleSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LiquidDrainTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PotionConsumeVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* NiagaraPotionConsumeVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName VFXBoneAttachmentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* PotionConsumeNiagaraComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<APotionBottlePhysics> PotionBottlePhysicsClass;
    
    AConsumablePotionItemTool(const FObjectInitializer& ObjectInitializer);
private:
    UFUNCTION(BlueprintCallable)
    void ThrowPotionBottleTimerExpired();
    
public:
    UFUNCTION(BlueprintCallable)
    void ThrowPotionBottle();
    
    UFUNCTION(BlueprintCallable)
    void DrinkPotion();
    
};

