#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ESpellCategory.h"
#include "SpellUpgradeState.h"
#include "SpellManagerBPInterface.generated.h"

UCLASS(Blueprintable)
class USpellManagerBPInterface : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumLoadouts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpellsPerLoadout;
    
    USpellManagerBPInterface();
    UFUNCTION(BlueprintCallable)
    static void SetTargetingSpell(int32 SpellLoadoutIndex, int32 SpellIndex, FName SpellName);
    
    UFUNCTION(BlueprintCallable)
    static void SetSpellFinisher(FName SpellName);
    
    UFUNCTION(BlueprintCallable)
    static void SetSpell(int32 LoadoutIndex, int32 SpellIndex, FName SpellName);
    
    UFUNCTION(BlueprintCallable)
    static void SetOverrideSpellLevel(int32 SpellLevel);
    
    UFUNCTION(BlueprintCallable)
    static void SetFinisherSpell(FName SpellName);
    
    UFUNCTION(BlueprintCallable)
    static void SetCurrentSpellLoadoutIndex(int32 LayoutIndex);
    
    UFUNCTION(BlueprintCallable)
    static bool IsUnlocked(FName SpellLockName);
    
    UFUNCTION(BlueprintCallable)
    static void GetTargetingSpells(TArray<FName>& SpellNames);
    
    UFUNCTION(BlueprintCallable)
    static TMap<FName, FSpellUpgradeState> GetSpellUpgradeMap();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> GetSpellsInCategory(ESpellCategory Category, bool IncludeLocked);
    
    UFUNCTION(BlueprintCallable)
    static bool GetSpellsFinisher(TArray<FName>& SpellNames);
    
    UFUNCTION(BlueprintCallable)
    static bool GetSpellsByGroup(int32 LoadoutIndex, TArray<FName>& SpellNames);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FString> GetSpellGroupNames();
    
    UFUNCTION(BlueprintCallable)
    static FName GetSpellFinisher();
    
    UFUNCTION(BlueprintCallable)
    static FName GetSpellCategory(const FString& SpellName);
    
    UFUNCTION(BlueprintCallable)
    static void GetSpell(int32 SpellLoadOut, int32 SpellIndex, FName& SpellName);
    
    UFUNCTION(BlueprintCallable)
    static void GetFinishingSpells(TArray<FName>& SpellNames);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetCurrentSpellLoadoutIndex();
    
    UFUNCTION(BlueprintCallable)
    static bool GetCurrentSpellLoadout(TArray<FName>& SpellNames);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetCurrentSpellIndex();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetAvailableSpellCount(bool IncludeLocked);
    
};

