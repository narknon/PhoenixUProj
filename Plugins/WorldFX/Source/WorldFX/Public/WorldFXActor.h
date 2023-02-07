#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldFXActor.generated.h"

class UWorldFXComponent;

UCLASS(Blueprintable)
class WORLDFX_API AWorldFXActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWorldFXComponent* FXComponent;
    
    AWorldFXActor();
    UFUNCTION(BlueprintCallable)
    void SetSpawnAttached(bool bNewSpawnAttached);
    
    UFUNCTION(BlueprintCallable)
    void ResetCascadeParameters();
    
    UFUNCTION(BlueprintCallable)
    void RefreshCascadeParameters();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetSpawnAttached(bool& bIsSpawnAttached);
    
    UFUNCTION(BlueprintCallable)
    void ForceRefreshPreview();
    
};

