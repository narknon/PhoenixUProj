#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EVolumeLoadIdentifier.h"
#include "AvaStreamingVolumeSet.generated.h"

class UAvaStreamingVolumeComponentBase;
class USceneComponent;

UCLASS(Blueprintable)
class AAvaStreamingVolumeSet : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHidesWithTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldAffectTileStreaming;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPauseTileStreaming;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TileRenderingMaxLod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AdditionalBoundsRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPreventExteriorRendering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreShellVolumes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EVolumeLoadIdentifier VolumeLoadIdentifier;
    
    AAvaStreamingVolumeSet();
    UFUNCTION(BlueprintCallable)
    void SetForcedStateStatus(bool bForced);
    
    UFUNCTION(BlueprintCallable)
    bool IsStateForced();
    
    UFUNCTION(BlueprintCallable)
    UAvaStreamingVolumeComponentBase* GetMaster();
    
};

