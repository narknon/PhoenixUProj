#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldFXPresetActor.generated.h"

class UWorldFXPresetComponent;

UCLASS(Blueprintable)
class WORLDFX_API AWorldFXPresetActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWorldFXPresetComponent* FXComponent;
    
    AWorldFXPresetActor();
    UFUNCTION(BlueprintCallable)
    void SetSpawnAttachedOverride(bool bNewSpawnAttached);
    
    UFUNCTION(BlueprintCallable)
    void ResetCascadeParameters();
    
    UFUNCTION(BlueprintCallable)
    void RefreshCascadeParameters();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetSpawnAttached(bool& bIsSpawnAttached);
    
    UFUNCTION(BlueprintCallable)
    void ForceRefreshPreview();
    
    UFUNCTION(BlueprintCallable)
    void ClearSpawnAttachedOverride(bool bNewSpawnAttached);
    
};

