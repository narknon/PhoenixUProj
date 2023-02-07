#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EEncounterEndReason.h"
#include "EncounterDuelTechniqueOverride.h"
#include "CombatVolumeGroup.generated.h"

class AActor;
class ACombatVolume;
class ADynamicObjectVolume;
class UCombatVolumeGroup;

UCLASS(Blueprintable, EditInlineNew)
class UCombatVolumeGroup : public UObject {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEncounterStartedEvent);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEncounterEndedEvent, EEncounterEndReason, EndReason);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCombatVolumeGroupDestroyed, const UCombatVolumeGroup*, Group);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCombatVolumeGroupDeathDelegate, ACombatVolume*, CombatVolume, AActor*, DeadActor);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCombatVolumeGroupActorSpawnedDelegate, ACombatVolume*, CombatVolume, AActor*, SpawnedActor);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterStartedEvent EncounterStartedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterEndedEvent EncounterEndedEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FCombatVolumeGroupDeathDelegate CombatVolumeGroupDeathDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FCombatVolumeGroupActorSpawnedDelegate CombatVolumeGroupActorSpawnedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCombatVolumeGroupDestroyed CombatVolumeGroupDestroyedEvent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<ACombatVolume*> VolumesInGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableDuelTechniques;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEncounterDuelTechniqueOverride> DuelTechniqueOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<ADynamicObjectVolume*> DOVsAggregated;
    
public:
    UCombatVolumeGroup();
    UFUNCTION(BlueprintCallable)
    bool TryStartEncounter();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActiveForCurrentEncounter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSet<ACombatVolume*> GetVolumes() const;
    
};

