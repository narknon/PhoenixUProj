#pragma once
#include "CoreMinimal.h"
#include "AvaStreamingVolumeSet.h"
#include "AvaTileRegionVolumeSet.generated.h"

class UWorld;

UCLASS(Blueprintable)
class AAvaTileRegionVolumeSet : public AAvaStreamingVolumeSet {
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
    
    AAvaTileRegionVolumeSet(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ForceDeactivate();
    
    UFUNCTION(BlueprintCallable)
    void ForceActivate();
    
};

