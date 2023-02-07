#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "PhysicsInterface.generated.h"

class AActor;
class ASpellTool;
class UInteractionArchitectAsset;

UINTERFACE(Blueprintable, MinimalAPI)
class UPhysicsInterface : public UInterface {
    GENERATED_BODY()
};

class IPhysicsInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool WingardiumStart(const ASpellTool* SpellTool, AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnWingardiumGhostStart(const ASpellTool* SpellTool, AActor* Instigator, const TArray<UInteractionArchitectAsset*>& DataAssets);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnWingardiumFailed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnWingardiumEnd(AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLeviosoFailed(bool InitiatedByPlayer);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLeviosoEnd(AActor* Instigator, bool InitiatedByPlayer);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFlipendoThrow(const ASpellTool* SpellTool, FVector ThrowDirection, FVector ThrowVelocity, FVector AngularVelocity, FVector Target, AActor* Instigator, const TArray<UInteractionArchitectAsset*>& DataAssets, FGameplayTagContainer Impact);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFlipendoFailed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnExpulsoThrow(FVector ThrowVelocity, FVector Target, AActor* Instigator, const TArray<UInteractionArchitectAsset*>& DataAssets, FGameplayTagContainer Impact);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDepulsoThrow(const ASpellTool* SpellTool, FVector ThrowVelocity, FVector Target, AActor* Instigator, const TArray<UInteractionArchitectAsset*>& DataAssets, FGameplayTagContainer Impact);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDepulsoFailed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAccioThrow(const ASpellTool* SpellTool, AActor* Instigator, FVector ThrowVelocity, const TArray<UInteractionArchitectAsset*>& DataAssets, FGameplayTagContainer Impact);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAccioFailed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAccioEnd(AActor* Instigator, bool TransitioningToWingardium);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool LeviosoStart(AActor* Instigator, FVector Location, FGameplayTagContainer Impact, const TArray<UInteractionArchitectAsset*>& DataAssets, bool InitiatedByPlayer, bool& OverrideEffects);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool LeviosoChargedStart(const ASpellTool* SpellTool, AActor* Instigator, FVector Location, FVector Velocity, bool InitiatedByPlayer, FGameplayTagContainer Impact, const TArray<UInteractionArchitectAsset*>& DataAssets, const FVector& ImpactDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool FlipendoStart(const ASpellTool* SpellTool, AActor* Instigator, FVector Location);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool ExpulsoStart(AActor* Instigator, FVector Location);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool DisallowWingardium();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool DisallowLevioso();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool DisallowFlipendo();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool DisallowDescendo();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool DisallowDepulso();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool DisallowAccio();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool DescendoStart(const ASpellTool* SpellTool, AActor* Instigator, FVector Velocity);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool DepulsoStart(const ASpellTool* SpellTool, AActor* Instigator, FVector Location);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool AccioStart(const ASpellTool* SpellTool, AActor* Instigator, FVector Velocity, const TArray<UInteractionArchitectAsset*>& DataAssets, const FVector& ImpactDirection);
    
};

