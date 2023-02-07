#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "VelocityTrackerComponent.generated.h"

class AActor;
class UAmbulatory_MovementComponent;
class UObjectStateInfo;
class UScheduledEntity;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UVelocityTrackerComponent : public UActorComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVelocityTrackerRemoved, AActor*, Actor);
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ComponentLifetime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Instigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* SendTargetActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObjectStateInfo* ObjectStateInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAmbulatory_MovementComponent* MovementComponent;
    
public:
    UVelocityTrackerComponent();
    UFUNCTION(BlueprintCallable)
    void SetMaintainVelocity(FVector Velocity, float Time);
    
    UFUNCTION(BlueprintCallable)
    void SetLastVelocity(FVector Vel);
    
    UFUNCTION(BlueprintCallable)
    void SetInstigator(AActor* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    void SetComponentLifetime(float Seconds);
    
    UFUNCTION(BlueprintCallable)
    void ResetComponentLifetime();
    
    UFUNCTION(BlueprintCallable)
    void RemoveWhenStopped(bool Value);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnFleshDestroyed(AActor* InActor, UScheduledEntity* InScheduledEntity);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetInstigator() const;
    
};

