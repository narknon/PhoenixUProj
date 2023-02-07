#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Interface_NiagaraHelpersInitializer.h"
#include "WorldFXFullTracker.h"
#include "WorldFXComponentBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WORLDFX_API UWorldFXComponentBase : public USceneComponent, public IInterface_NiagaraHelpersInitializer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWorldFXFullTracker Tracker;
    
    UWorldFXComponentBase();
    UFUNCTION(BlueprintCallable)
    void ForceRefreshPreview();
    
    
    // Fix for true pure virtual functions not being implemented
};

