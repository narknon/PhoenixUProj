#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "EFT_FromType.h"
#include "EFT_TravelType.h"
#include "FastTravelFinishedBPDelegate.h"
#include "FastTravelLocationName.h"
#include "TravelLocation.h"
#include "FastTravelManager.generated.h"

class AActor;
class AFastTravelLocation;
class AFloo;
class ASceneRigActor;
class UFastTravelManager;
class UFlooListEntry;

UCLASS(Blueprintable)
class PHOENIX_API UFastTravelManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWaitEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AFloo* SourceFlooRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString TargetFlooName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AFloo* TargetFloo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UFlooListEntry*> FlooList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FTravelLocation> FastTravelLocations;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFastTravelFinishedBP SceneRigCallback;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASceneRigActor* WaitSceneRigActor;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* LastActorUsingFloo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFlooListEntry* FlooListEntry;
    
public:
    UFastTravelManager();
    UFUNCTION(BlueprintCallable)
    void UnlockLocationByName(const FString& LocationName);
    
    UFUNCTION(BlueprintCallable)
    void UnlockLocationByActor(AFastTravelLocation* locationActor);
    
    UFUNCTION(BlueprintCallable)
    void UnlockLocation(const FString& LocationID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestExec();
    
    UFUNCTION(BlueprintCallable)
    void StartFastTravelWithCallbackBP(FVector ToLocation, FFastTravelFinishedBP Callback, TEnumAsByte<EFT_FromType> FromType, EFT_TravelType FastTravelControlType);
    
    UFUNCTION(BlueprintCallable)
    void StartFastTravelUsingIDWithCallbackBP(const FString& LocationID, FFastTravelFinishedBP Callback, TEnumAsByte<EFT_FromType> FromType, EFT_TravelType FastTravelControlType);
    
    UFUNCTION(BlueprintCallable)
    void StartFastTravelUsingID(const FString& LocationID, TEnumAsByte<EFT_FromType> FromType, EFT_TravelType FastTravelControlType);
    
    UFUNCTION(BlueprintCallable)
    bool StartFastTravelToNamedLocation(FFastTravelLocationName LocationName, TEnumAsByte<EFT_FromType> FromType, EFT_TravelType FastTravelControlType);
    
    UFUNCTION(BlueprintCallable)
    bool StartFastTravelToClosestUnlockedSaveLocationToPlayer();
    
    UFUNCTION(BlueprintCallable)
    bool StartFastTravelToClosestUnlockedSaveLocation(FVector CheckLocation);
    
    UFUNCTION(BlueprintCallable)
    void StartFastTravel(AActor* TravelActorIn, FVector ToLocation, const FString& EndPointActorNameIn, float Yaw, TEnumAsByte<EFT_FromType> FromType, EFT_TravelType FastTravelControlType);
    
    UFUNCTION(BlueprintCallable)
    void SetWaitEnabled(bool Enable);
    
    UFUNCTION(BlueprintCallable)
    void SetForceFastTravelLocationName(const FString& FastTravelID, const FString& StartInMap);
    
    UFUNCTION(BlueprintCallable)
    void SetFastTravelDisabled(bool Disabled);
    
    UFUNCTION(BlueprintCallable)
    void PlayWaitSceneRig(bool WaitAtEnd);
    
    UFUNCTION(BlueprintCallable)
    void PlayerSelectedFloo(AActor* ActorUsingFloo, const FString& FastTravelID);
    
    UFUNCTION(BlueprintCallable)
    void PlayerExitingFloo(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable)
    void PlayerExitedFloo(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable)
    void PlayerEnteringFloo(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable)
    void PlayerEnteredFloo(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable)
    void PlayerDroppedPowder(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable)
    void PlayerCanceledFloo(AActor* ActorUsingFloo);
    
    UFUNCTION(BlueprintCallable)
    void LockLocationByName(const FString& LocationName);
    
    UFUNCTION(BlueprintCallable)
    void LockLocationByActor(AFastTravelLocation* locationActor);
    
    UFUNCTION(BlueprintCallable)
    bool IsWaitEnabled();
    
    UFUNCTION(BlueprintCallable)
    bool IsFlooLoaded(const FString& Name, AFloo*& TargetFlooIn);
    
    UFUNCTION(BlueprintCallable)
    bool IsFastTravelUnlockedForLocation(const FString& LocationID);
    
    UFUNCTION(BlueprintCallable)
    bool IsFastTravelTutorialActive();
    
    UFUNCTION(BlueprintCallable)
    bool IsFastTravelling();
    
    UFUNCTION(BlueprintCallable)
    bool IsFastTravelDisabled();
    
    UFUNCTION(BlueprintCallable)
    bool IsFastTravelDebugUnlockAllActive();
    
    UFUNCTION(BlueprintCallable)
    bool IsFastTravelAvailableForLocation(const FString& LocationID);
    
    UFUNCTION(BlueprintCallable)
    bool IsFastTravelAvailable();
    
    UFUNCTION(BlueprintCallable)
    bool HasHardLoadFastTravelLocation();
    
    UFUNCTION(BlueprintCallable)
    float GetHardLoadFastTravelYaw();
    
    UFUNCTION(BlueprintCallable)
    FVector GetHardLoadFastTravelLocaiton();
    
    UFUNCTION(BlueprintCallable)
    FString GetForceFastTravelLocationName();
    
    UFUNCTION(BlueprintCallable)
    void GetFastTravelLocationsByType(const FString& Type, TArray<FTravelLocation>& Locations);
    
    UFUNCTION(BlueprintCallable)
    void GetFastTravelLocations(TArray<FString>& Names, TArray<FVector>& Locations);
    
    UFUNCTION(BlueprintCallable)
    bool GetFastTravelLocationFromName(const FString& Name, FVector& Location);
    
    UFUNCTION(BlueprintCallable)
    bool GetFastTravelLocationDataFromName(const FString& Name, FTravelLocation& Location);
    
    UFUNCTION(BlueprintCallable)
    bool GetClosestUnlockedSaveLocationToPlayer(FTravelLocation& LocationData);
    
    UFUNCTION(BlueprintCallable)
    bool GetClosestUnlockedSaveLocation(FVector CheckLocation, FTravelLocation& LocationData);
    
    UFUNCTION(BlueprintCallable)
    void GetAvailableFloos(TArray<FTravelLocation>& AvailableFloos);
    
    UFUNCTION(BlueprintCallable)
    static UFastTravelManager* Get();
    
    UFUNCTION(BlueprintCallable)
    void FinishWait();
    
    UFUNCTION(BlueprintCallable)
    bool FindFastTravelLocationData(const FString& LocationID, FTravelLocation& LocationData);
    
    UFUNCTION(BlueprintCallable)
    bool FastTravelTutorialCompleted();
    
    UFUNCTION(BlueprintCallable, Exec)
    void FastTravel_To(const FString& LocationID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void FastTravel_TeleportToXYZ(float X, float Y, float Z);
    
    UFUNCTION(BlueprintCallable, Exec)
    void FastTravel_EnableWaitSR(bool tf);
    
    UFUNCTION(BlueprintCallable, Exec)
    void FastTravel_DisableNextWaitSR(bool tf);
    
    UFUNCTION(BlueprintCallable)
    void EnableWaitSR(bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    void DoWait();
    
    UFUNCTION(BlueprintCallable)
    void DebugLogFastTravelInformation(const FString& Data1, const FString& Data2);
    
    UFUNCTION(BlueprintCallable)
    void ClearHardLoadFastTravelLocaiton();
    
    UFUNCTION(BlueprintCallable)
    void ClearForceFastTravelLocationName();
    
    UFUNCTION(BlueprintCallable)
    void AddFastTravelLocationWithLockToDB(AFastTravelLocation* locationActor, const FString& LocationName, FVector Location, FVector BeaconLocation, float ZRot, bool isSaveLocation, bool IsBuiltNightly, bool ShowOnMap, bool Locked);
    
    UFUNCTION(BlueprintCallable)
    void AddFastTravelLocationToDB(const FString& LocationName, FVector Location, FVector BeaconLocation, float ZRot, const FString& RegionId, bool isSaveLocation, bool IsBuiltNightly, bool ShowOnMap);
    
    UFUNCTION(BlueprintCallable)
    bool ActorDismount(AActor* InActor);
    
};

