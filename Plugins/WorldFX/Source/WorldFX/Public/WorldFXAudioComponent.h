#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "WorldFXAudioEvent.h"
#include "WorldFXAudioTracker.h"
#include "WorldFXAudioComponent.generated.h"

class UWorldFXRule;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WORLDFX_API UWorldFXAudioComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWorldFXRule* Rule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXAudioEvent SFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWorldFXAudioTracker Tracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnAttached;
    
    UWorldFXAudioComponent();
    UFUNCTION(BlueprintCallable)
    void SetSpawnAttached(bool bNewSpawnAttached);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetSpawnAttached(bool& bIsSpawnAttached);
    
    UFUNCTION(BlueprintCallable)
    void ForceRefreshPreview();
    
};

