#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "EBeaconState.h"
#include "EBeaconType.h"
#include "BeaconManager.generated.h"

class AActor;
class UBeaconInfo;
class UBeaconManager;
class UScheduledEntity;

UCLASS(Blueprintable)
class UBeaconManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> BeaconObjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, UBeaconInfo*> BeaconObjectsMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> DynamicBeaconObjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> StaticBeaconObjectsWithWorldName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> DiscoverableObjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> EnterExitObjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> HudBeaconObjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> CurrentProximityHudBeacons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> WorldTransitionProxies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> BroomRevelioHUDBeacons;
    
public:
    UBeaconManager();
    UFUNCTION(BlueprintCallable)
    void UpdateExpansionTentPlayer(FVector teleportPosition);
    
    UFUNCTION(BlueprintCallable)
    static void UnRegisterBeaconByHandleBP(int64 ObjectHandle);
    
    UFUNCTION(BlueprintCallable)
    void SetBeaconStateByName(EBeaconType BeaconType, const FString& BeaconName, bool ActiveState);
    
    UFUNCTION(BlueprintCallable)
    static void SetBeaconStateBP(int32 ObjectHandle, EBeaconState BeaconState);
    
    UFUNCTION(BlueprintCallable)
    void SetBeaconRangesByHandle(int32 ObjectHandle, int32 InActivationDist, int32 InEnterExitDist);
    
    UFUNCTION(BlueprintCallable)
    static int64 RegisterStaticBeaconBP(EBeaconType BeaconType, const FString& BeaconName, const FString& BeaconIcon, const FName& BeaconWorld, FVector BeaconPos, bool ShowOnHUD, bool ShowDistanceOnHud, FName BeaconableId);
    
    UFUNCTION(BlueprintCallable)
    static void RegisterSanctuaryExit(const FString& SanctuaryWorldName);
    
    UFUNCTION(BlueprintCallable)
    static void RegisterExpansionTent(const FString& tentID, FVector Position, bool bIsEntrance);
    
    UFUNCTION(BlueprintCallable)
    static int64 RegisterDynamicBeaconScheduledEntityBP(EBeaconType BeaconType, const FString& BeaconName, const FString& BeaconIcon, const FName& BeaconWorld, FVector BeaconPos, UScheduledEntity* NewBeaconScheduledEntity, bool ShowOnHUD, bool ShowDistanceOnHud);
    
    UFUNCTION(BlueprintCallable)
    static int64 RegisterDynamicBeaconObjectBP(EBeaconType BeaconType, const FString& BeaconName, const FString& BeaconIcon, const FName& BeaconWorld, FVector BeaconPos, AActor* NewBeaconObject, bool ShowOnHUD, bool ShowDistanceOnHud);
    
    UFUNCTION(BlueprintCallable)
    static void RegisterDungeonExit(FVector Position, FName UID, bool Disable);
    
    UFUNCTION(BlueprintCallable)
    static void RegisterDungeonEntrance(const FString& DungeonName, FVector Position, float ZRot, FVector BeaconPosition, int32 EntranceIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnRevelioStart(float RevelioViewMeters);
    
    UFUNCTION(BlueprintCallable)
    void OnRevelioEnd();
    
    UFUNCTION(BlueprintCallable)
    void OnNewGame();
    
    UFUNCTION(BlueprintCallable)
    void GetDungeonReqirementsByName(const FString& DungeonName, TArray<FText>& RequiredSpells, TArray<FText>& CompletionSpells);
    
    UFUNCTION(BlueprintCallable)
    UBeaconInfo* GetBeaconByHandleBP(int32 ObjectHandle);
    
    UFUNCTION(BlueprintCallable)
    static UBeaconManager* Get();
    
};

