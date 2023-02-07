#pragma once
#include "CoreMinimal.h"
#include "Field/FieldSystemTypes.h"
#include "Chaos/CacheManagerActor.h"
#include "Chaos/ChaosGameplayEventDispatcher.h"
#include "Chaos/ChaosNotifyHandlerInterface.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=ChaosSolverEngine -ObjectName=ChaosRemovalCompletedEvent -FallbackName=ChaosRemovalCompletedEvent
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "SavedMeshSettings2.h"
#include "Chaos/ChaosRemovalCompletedEvent.h"
#include "RepairComponent.generated.h"

class AActor;
class AFieldSystemActor;
class UGeometryCollection;
class UGeometryCollectionComponent;
class UMeshComponent;
class UMultiFX2_Base;
class UObjectStateInfo;
class UPrimitiveComponent;
class URepairInfo;
class UStaticMeshComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API URepairComponent : public UActorComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRepairComplete, UActorComponent*, RepairDestroyComp);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRepairComplete OnRepairComplete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AFieldSystemActor* AnchorActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGeometryCollectionComponent* GeometryCollectionComponent;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObjectStateInfo> ObjectStateInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> DestroyFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> ObjectFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UPrimitiveComponent*> m_chunkParticleArray;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UMeshComponent>, FSavedMeshSettings2> m_meshSettingMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> m_childActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UPrimitiveComponent*> m_childParticleArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* DestroyedBaseMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGeometryCollection* GeometryCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URepairInfo* RepairInfo;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FObservedComponent ObservedComponent;
    
    URepairComponent();
    UFUNCTION(BlueprintCallable)
    void OnHitCallback(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable)
    void OnChaosPhysicsCollision(const FChaosPhysicsCollisionInfo& CollisionInfo);
    
    UFUNCTION(BlueprintCallable)
    void HandleRemovalCompletedEvent(const FChaosRemovalCompletedEvent& RemovalCompletedEvent);
    
    UFUNCTION(BlueprintCallable)
    void HandleBreakEvent(const FChaosBreakEvent& BreakEvent);
    
    UFUNCTION(BlueprintCallable)
    void EntireRepairComplete();
    
    UFUNCTION(BlueprintCallable)
    void ApplyDestuctiveForce(const FVector& HitLocation, const FVector& HitDirection, float Radius, float ObjectStrain, float ImpulseStrength, float RadialImpulseStrength, float AngularForceMultiplier);
    
    UFUNCTION(BlueprintCallable)
    void AddRadialImpulse(FVector Location, float Radius, float Strength, float AngularForceMultiplier, TEnumAsByte<EFieldFalloffType> Falloff, bool bVelChange);
    
    UFUNCTION(BlueprintCallable)
    void AddImpulse(FVector Impulse, FVector ImpulseLocation, float Radius, float AngularForceMultiplier, TEnumAsByte<EFieldFalloffType> Falloff, bool bVelChange);
    
};

