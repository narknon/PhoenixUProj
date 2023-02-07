#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CustomButtonWidget.h"
#include "Engine/EngineTypes.h"
#include "Engine/TargetPoint.h"
#include "CombatVolume.generated.h"

class AActor;
class ADynamicObjectVolume;
class AEncounterVolume;
class AExplosiveBarrel;
class UBoxComponent;
class UCombatDOVCollection;
class UCombatVolumeGroup;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class ACombatVolume : public ATargetPoint {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NonPIEDuplicateTransient, meta=(AllowPrivateAccess=true))
    UCombatVolumeGroup* OwningGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor WireColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartEncounterOnEnter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerClearDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* BoxComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<ADynamicObjectVolume*> OverlappedDOVs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<AEncounterVolume*> OverlappedEncounterVolumes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FCustomButtonWidget VolumesRefreshButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCombatDOVCollection* LinkedDOVCollection;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<TWeakObjectPtr<AExplosiveBarrel>> ExplosiveBarrels;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<TWeakObjectPtr<AActor>> Throwables;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<TWeakObjectPtr<AActor>> SendTargets;
    
public:
    ACombatVolume();
private:
    UFUNCTION(BlueprintCallable)
    void OnActorSpawnInFinished(AActor* SpawnedActor);
    
    UFUNCTION(BlueprintCallable)
    void OnActorDeadEvent(AActor* DeadActor);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCombatVolumeGroup* GetGroup();
    
protected:
    UFUNCTION(BlueprintCallable)
    void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
};

