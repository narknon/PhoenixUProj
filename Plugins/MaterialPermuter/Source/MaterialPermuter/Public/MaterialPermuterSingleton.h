#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "MaterialPermuterLoadTriggerProperty.h"
#include "MaterialPermuterMIDCache.h"
#include "MaterialPermuterSwapTracker.h"
#include "MaterialSwapActorFadeStates.h"
#include "MaterialPermuterSingleton.generated.h"

class UMaterialPermuterLibrary;
class UMaterialPermuterLiveMaterials;
class UObject;

UCLASS(Blueprintable, NotPlaceable, Transient)
class MATERIALPERMUTER_API AMaterialPermuterSingleton : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialPermuterLibrary* Library;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialPermuterLiveMaterials* LiveMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMaterialPermuterMIDCache MIDCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMaterialPermuterSwapTracker ActiveSwaps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle ActiveSwapsUpdateTimerHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMaterialSwapActorFadeStates ActorFadeStates;
    
public:
    AMaterialPermuterSingleton(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    static void SetLoadingTrigger(UObject* TriggerOwner, FName Trigger);
    
    UFUNCTION(BlueprintCallable)
    static void ProhibitActorFade(AActor* Actor, bool bProhibit);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PauseAllActorFading(UObject* WorldContextObject, bool bPause);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void LoadingTriggerSet(FName Trigger, bool& bSet);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void IsLoadingTriggerSet(UObject* TriggerOwner, FName Trigger, bool& bSet);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsAllActorFadingPaused(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsActorFadeProhibited(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName GetTriggerPropertyName(FMaterialPermuterLoadTriggerProperty TriggerProperty);
    
    UFUNCTION(BlueprintCallable)
    static void ClearLoadingTrigger(UObject* TriggerOwner, FName Trigger);
    
};

