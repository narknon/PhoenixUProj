#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldFXAudioActor.generated.h"

class UWorldFXAudioComponent;

UCLASS(Blueprintable)
class WORLDFX_API AWorldFXAudioActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWorldFXAudioComponent* SFXComponent;
    
    AWorldFXAudioActor();
    UFUNCTION(BlueprintCallable)
    void SetSpawnAttached(bool bNewSpawnAttached);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetSpawnAttached(bool& bIsSpawnAttached);
    
    UFUNCTION(BlueprintCallable)
    void ForceRefreshPreview();
    
};

