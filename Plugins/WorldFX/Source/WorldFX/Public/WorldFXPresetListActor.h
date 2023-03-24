#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldFXPresetListActor.generated.h"

class UWorldFXPresetComponent;

UCLASS(Blueprintable)
class WORLDFX_API AWorldFXPresetListActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWorldFXPresetComponent*> Presets;
    
    AWorldFXPresetListActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetSpawnAttachedOverride(bool bNewSpawnAttached);
    
    UFUNCTION(BlueprintCallable)
    void ResetCascadeParameters();
    
    UFUNCTION(BlueprintCallable)
    void RefreshCascadeParameters();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetSpawnAttached(bool& bIsSpawnAttached);
    
    UFUNCTION(BlueprintCallable)
    void ForceRefreshPreviews();
    
    UFUNCTION(BlueprintCallable)
    void ClearSpawnAttachedOverride();
    
};

