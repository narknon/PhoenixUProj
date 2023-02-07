#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "HealthInterface.generated.h"

class AActor;
class UGeometryCollectionComponent;
class UPrimitiveComponent;
class URepairComponent;

UINTERFACE(Blueprintable, MinimalAPI)
class UHealthInterface : public UInterface {
    GENERATED_BODY()
};

class IHealthInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHealed(float healAmount, UPrimitiveComponent* PrimComp);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnGeometryCollectionSpawned(URepairComponent* RepairComponent, UGeometryCollectionComponent* GeometryCollectionComponent, float impulseStr, float Radius, FVector HitLocation, FVector HitDirection, bool bCompletelyBroken);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnGeometryCollectionDamaged(URepairComponent* RepairComponent, UGeometryCollectionComponent* GeometryCollectionComponent, float impulseStr, float Radius, FVector HitLocation, FVector HitDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnGeometryCollectionCompletelyBroken(URepairComponent* RepairComponent, UGeometryCollectionComponent* GeometryCollectionComponent, float impulseStr, float Radius, FVector HitLocation, FVector HitDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFailedToBeHealed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFailedToBeDestroyed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFailedToBeDamaged(float DamageAmount, FVector HitLocation, FVector HitDirection, UPrimitiveComponent* PrimComp, FGameplayTagContainer MunitionTagContainer, AActor* Instigator, FVector Velocity);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDoneRepairing();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCriticalHealthReached();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBeginRepairing();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAttemptToRepair();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAttemptToHeal();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool NearDeathKneeling(float DamageAmount, AActor* Instigator, FGameplayTagContainer MunitionTagContainer, FVector Velocity);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool Destroyed(float DamageAmount, AActor* Instigator, FGameplayTagContainer MunitionTagContainer, FVector Velocity);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool Damaged(float DamageAmount, FVector HitLocation, FVector HitDirection, UPrimitiveComponent* PrimComp, FGameplayTagContainer MunitionTagContainer, AActor* Instigator, FVector Velocity);
    
};

