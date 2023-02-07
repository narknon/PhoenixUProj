#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "EventLocationResult.h"
#include "LocationBasedDatabaseTables.generated.h"

class AAmbientCreatureSpawnVolume;
class ADynamicObjectVolume;
class AFastTravelLocation;
class AMountZoneVolumeBase;
class UWorldEventCondition;

UCLASS(Blueprintable)
class PHOENIX_API ULocationBasedDatabaseTables : public UObject {
    GENERATED_BODY()
public:
    ULocationBasedDatabaseTables();
private:
    UFUNCTION(BlueprintCallable)
    static void RecordWorldEventLocationMeta(const FString& Name, const float StreamInRadius, const float StreamOutRadius);
    
    UFUNCTION(BlueprintCallable)
    static void RecordWorldEventDatabaseLocation(const FString& Name, const FString& Guid, FVector Position, float ZRot);
    
    UFUNCTION(BlueprintCallable)
    static void RecordWorldEventDatabaseDescriptors(const FString& Name, const FGameplayTagContainer& locationDescriptors, const TArray<TSoftObjectPtr<UWorldEventCondition>> Conditions);
    
    UFUNCTION(BlueprintCallable)
    static void RecordVaultDatabaseLocation(const FString& Name, FVector Position, float ZRot);
    
    UFUNCTION(BlueprintCallable)
    static void RecordTentDatabaseLocation(const FString& Name, FVector Position, float ZRot);
    
    UFUNCTION(BlueprintCallable)
    static void RecordSphinxPuzzleDatabaseLocation(const FString& Name, FVector Position, float ZRot);
    
    UFUNCTION(BlueprintCallable)
    static void RecordRuinDatabaseLocation(const FString& Name, FVector Position, float ZRot);
    
    UFUNCTION(BlueprintCallable)
    static void RecordObjectAndOwner(const FString& Name, const FString& Owner);
    
public:
    UFUNCTION(BlueprintCallable)
    static void RecordMountZoneLocation(const AMountZoneVolumeBase* InVolume);
    
private:
    UFUNCTION(BlueprintCallable)
    static void RecordMiscDatabaseLocation(const FString& Name, FVector Position, float ZRot);
    
    UFUNCTION(BlueprintCallable)
    static void RecordKnowledgeLocationDatabaseLocation(const FString& Name, FVector Position, float ZRot);
    
    UFUNCTION(BlueprintCallable)
    static void RecordKnowledgeInvestigatableDatabaseLocation(const FString& Name, FVector Position, float ZRot);
    
    UFUNCTION(BlueprintCallable)
    static void RecordHamletDatabaseLocation(const FString& Name, FVector Position, float ZRot);
    
    UFUNCTION(BlueprintCallable)
    static void RecordFastTravelDatabaseLocation(const FString& Name, FVector Position, FVector BeaconPosition, float ZRot, AFastTravelLocation* locationActor);
    
    UFUNCTION(BlueprintCallable)
    static void RecordEnemyDenLocationsDatabaseLocation(const FString& Name, FVector Position, float ZRot);
    
    UFUNCTION(BlueprintCallable)
    static void RecordDungeonChestDatabaseOwner(const FString& Name, const FString& Owner);
    
    UFUNCTION(BlueprintCallable)
    static void RecordDungeonChestDatabaseLocation(const FString& Name, FVector Position, float ZRot);
    
    UFUNCTION(BlueprintCallable)
    static void RecordDevMiscDatabaseLocation(const FString& Name, FVector Position, float ZRot);
    
    UFUNCTION(BlueprintCallable)
    static void RecordDevBanditCampDatabaseLocation(const FString& Name, FVector Position, float ZRot);
    
    UFUNCTION(BlueprintCallable)
    static void RecordClusterDatabaseLocation(const FString& Name, FVector Position, float ZRot);
    
    UFUNCTION(BlueprintCallable)
    static void RecordChestDatabaseOwner(const FString& Name, const FString& Owner);
    
public:
    UFUNCTION(BlueprintCallable)
    static void RecordCharacterSpawnLocation(const ADynamicObjectVolume* InVolume);
    
    UFUNCTION(BlueprintCallable)
    static void RecordBroomTestPaths();
    
    UFUNCTION(BlueprintCallable)
    static void RecordBroomRacePath(const FString& RaceName, const FString& PathName, const int32 PathIndex, const TArray<FVector>& PathPoints);
    
    UFUNCTION(BlueprintCallable)
    static void RecordBroomRaceGates(const FString& RaceName, const TArray<FTransform>& RaceGateTransforms, const TArray<FString>& GateTypes);
    
private:
    UFUNCTION(BlueprintCallable)
    static void RecordBeastDenDatabaseLocation(const FString& Name, FVector Position, float ZRot);
    
    UFUNCTION(BlueprintCallable)
    static void RecordBanditCampDatabaseLocation(const FString& Name, FVector Position, float ZRot);
    
    UFUNCTION(BlueprintCallable)
    static void RecordAncientMagicDatabaseLocation(const FString& Name, FVector Position, float ZRot);
    
public:
    UFUNCTION(BlueprintCallable)
    static void RecordAmbientCreatureSpawnLocation(const AAmbientCreatureSpawnVolume* InVolume);
    
    UFUNCTION(BlueprintCallable)
    static void GetWorldEventLocations(const FGameplayTagContainer& LocationRequiredDescriptors, const FGameplayTagContainer& LocationDeniedDescriptors, TArray<FEventLocationResult>& OutResults);
    
};

