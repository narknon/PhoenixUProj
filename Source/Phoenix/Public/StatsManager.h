#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StatList.h"
#include "StatsManager.generated.h"

class UStatsManager;

UCLASS(Blueprintable)
class PHOENIX_API UStatsManager : public UObject {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FStatChangedEvent, FName, Key, int32, Value, int32, Delta);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStatChangedEvent StatChangedEvent;
    
    UStatsManager();
    UFUNCTION(BlueprintCallable)
    static void UpdateStat(const FName Key, const int32 Delta);
    
    UFUNCTION(BlueprintCallable)
    static bool StatExists(const FName Key);
    
    UFUNCTION(BlueprintCallable)
    static void SetStatBit(const FName Key, const int32 bit);
    
    UFUNCTION(BlueprintCallable)
    static void SetStat(const FName Key, const int32 Value);
    
    UFUNCTION(BlueprintCallable)
    static int32 ReadStat(const FName Key);
    
    UFUNCTION(BlueprintCallable)
    static int32 ReadSetBitCount(const FName Key);
    
    UFUNCTION(BlueprintCallable)
    static bool ReadBitSet(const FName Key, const int32 bit);
    
    UFUNCTION(BlueprintCallable)
    void OnGameToBeSaved();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName GetStatName(const FStatList StatList);
    
    UFUNCTION(BlueprintCallable)
    static UStatsManager* Get();
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameStatSet(const FString& StatKey, int32 StatValue);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameStatGet(const FString& StatKey);
    
    UFUNCTION(BlueprintCallable)
    static bool DeleteStat(FName Key);
    
    UFUNCTION(BlueprintCallable)
    static void ClearStatBit(const FName Key, const int32 bit);
    
    UFUNCTION(BlueprintCallable)
    static bool AddNewStat(FName StatID, const int32 Value);
    
};

