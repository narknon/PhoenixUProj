#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "SpellInterface.generated.h"

class AActor;
class ASpellTool;
class UInteractionArchitectAsset;
class USpellToolRecord;

UINTERFACE(Blueprintable, MinimalAPI)
class USpellInterface : public UInterface {
    GENERATED_BODY()
};

class ISpellInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpellTooWeak(AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpellIneffective(AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpellEffective(AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnOverlappedBySpell(ASpellTool* SpellTool, AActor* Instigator, USpellToolRecord* SpellToolRecord, FName SpellType, FGameplayTagContainer Impact, const FVector& MunitionLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHitBySpell(const ASpellTool* SpellTool, AActor* Instigator, USpellToolRecord* SpellToolRecord, FName SpellType, const FHitResult& Hit, const FVector& ImpactDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAffectedBySpellEnd(const ASpellTool* SpellTool, AActor* Instigator, USpellToolRecord* SpellToolRecord, FName SpellType, FGameplayTagContainer Impact);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAffectedBySpell(const ASpellTool* SpellTool, AActor* Instigator, const TArray<UInteractionArchitectAsset*>& DataAssets, USpellToolRecord* SpellToolRecord, FName SpellType, FGameplayTagContainer Impact, const FHitResult& Hit, const FVector& ImpactDirection);
    
};

