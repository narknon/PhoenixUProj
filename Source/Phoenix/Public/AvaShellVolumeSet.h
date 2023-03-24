#pragma once
#include "CoreMinimal.h"
#include "AvaStreamingVolumeSet.h"
#include "AvaShellVolumeSet.generated.h"

class AActor;
class ATriggerBox;
class ULevelStreamingDynamic;
class UWorld;

UCLASS(Blueprintable)
class AAvaShellVolumeSet : public AAvaStreamingVolumeSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> LevelToStream;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* LevelPlacementActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ATriggerBox* VolumeToIntersectAgainsStreamingVolumes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULevelStreamingDynamic* LoadedLevel;
    
    AAvaShellVolumeSet(const FObjectInitializer& ObjectInitializer);
};

