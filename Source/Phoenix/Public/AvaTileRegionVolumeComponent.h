#pragma once
#include "CoreMinimal.h"
#include "AvaStreamingVolumeComponentBase.h"
#include "AvaTileRegionVolumeComponent.generated.h"

class UWorld;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAvaTileRegionVolumeComponent : public UAvaStreamingVolumeComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 UnloadCO_: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 UnloadFO_: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 UnloadHN_: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 UnloadHS_: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 UnloadSW_: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 UnloadTU_: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorld>> TilesToForceLoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorld>> TilesToForceUnload;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorld>> TilesToForceHide;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorld>> TilesToOnlyLoad;
    
    UAvaTileRegionVolumeComponent();
    UFUNCTION(BlueprintCallable)
    void RemoveTiles();
    
    UFUNCTION(BlueprintCallable)
    void ForceUnload();
    
    UFUNCTION(BlueprintCallable)
    void ForceLoad();
    
    UFUNCTION(BlueprintCallable)
    void AddTiles();
    
};

