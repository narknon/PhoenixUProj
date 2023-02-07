#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CooldownPickup.generated.h"

class UMultiFX2_Base;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class ACooldownPickup : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> SpawnFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> CollectedFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> FizzleFX;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* Prim;
    
public:
    ACooldownPickup();
    UFUNCTION(BlueprintCallable)
    void UnpauseAndShow();
    
    UFUNCTION(BlueprintCallable)
    void PauseAndHide();
    
    UFUNCTION(BlueprintCallable)
    void OnPickedUp(AActor* InActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDisablePickupTime() const;
    
    UFUNCTION(BlueprintCallable)
    bool CanPickup();
    
};

