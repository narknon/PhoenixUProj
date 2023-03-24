#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "Engine/TriggerBox.h"
#include "EAmbientCreatureSpawnVolumePriority.h"
#include "EAmbientCreatureSpawnVolumeType.h"
#include "AmbientCreatureSpawnVolume.generated.h"

class AActor;

UCLASS(Blueprintable)
class AAmbientCreatureSpawnVolume : public ATriggerBox {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EAmbientCreatureSpawnVolumeType VolumeType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo CreatureGroupSelector;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EAmbientCreatureSpawnVolumePriority VolumePriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RangeMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSuppressSpawning;
    
public:
    AAmbientCreatureSpawnVolume(const FObjectInitializer& ObjectInitializer);
private:
    UFUNCTION(BlueprintCallable)
    void OnEndOverlap(AActor* SelfActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnBeginOverlap(AActor* SelfActor, AActor* OtherActor);
    
};

