#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TimeEvent.h"
#include "GameplayProperty_Float.h"
#include "Moddable.h"
#include "ESanctuaryIdentity.h"
#include "SanctuaryExpansionDefinition.h"
#include "SanctuaryManager.generated.h"

class AActor;
class ASanctuaryItemGenerator;
class USanctuaryExpansionManager;
class USanctuaryManager;

UCLASS(Blueprintable)
class USanctuaryManager : public UObject, public IModdable {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USanctuaryExpansionManager* ExpansionManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float GeneratorTimeMultiplier;
    
public:
    USanctuaryManager();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    void SetInitialSanctuaryCustomizationChoice(const UObject* WorldContextObject, const FString& InChoice);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SetCustomNameForChest(int32 ObjectUID, const FString& NewName) const;
    
    UFUNCTION(BlueprintCallable)
    void RemoveCreatureToyFromBiome(const AActor* ToyActor);
    
    UFUNCTION(BlueprintCallable)
    void OnToyChestEndPlay(const AActor* ToyChestActor);
    
    UFUNCTION(BlueprintCallable)
    void OnToyChestBeginPlay(const AActor* ToyChestActor);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnStartNewInterval(const FTimeEvent& InTimeEvent);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnSanctuaryItemGeneratorFinished(const FTimeEvent& InTimeEvent);
    
    UFUNCTION(BlueprintCallable)
    void OnNewGame();
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    FTimespan GetSanctuaryItemGeneratorTimeRemaining(ASanctuaryItemGenerator* ItemGenerator) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    float GetSanctuaryItemGeneratorProgress(ASanctuaryItemGenerator* ItemGenerator) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void GetSanctuaryItemGeneratorItemHeld(ASanctuaryItemGenerator* ItemGenerator, FName& OutItemHeld, int32& OutQuantity) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    FName GetSanctuaryItemGeneratorGuaranteedOutputItem(ASanctuaryItemGenerator* ItemGenerator) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<FSanctuaryExpansionDefinition> GetSanctuaryExpansions(FName AreaID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetNurturingSpaceIDFromBiomeLevel(const FString& LevelPath) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetNurturingSpaceIDFromBiomeID(FName BiomeID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetNurtureSpacesContainingCreatures(bool bIncludeInventory, bool bIncludeSanctuaryBiomes, bool bIncludeOther, TSet<FName>& OutNurtureSpaceIDs) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ESanctuaryIdentity GetInitialSanctuaryLightingIdentity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USanctuaryExpansionManager* GetExpansionManager() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    FString GetCustomNameForChest(int32 ObjectUID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetBiomeIDFromNurturingSpaceID(FName NurturingSpaceID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetBiomeIDFromLevel(const FString& LevelPath) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static USanctuaryManager* Get(bool bCreateIfNull);
    
    UFUNCTION(BlueprintCallable)
    void AddCreatureToyToBiome(const AActor* ToyActor);
    
    
    // Fix for true pure virtual functions not being implemented
};

