#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "DynamicObjectLoadInfo.h"
#include "ObjectLoadedEventDelegate.h"
#include "ObjectTrackerData.h"
#include "DynamicObjectManager.generated.h"

class AActor;
class ARandomEncounterActor;
class UDynamicObjectManager;
class UGameInstance;

UCLASS(Blueprintable, NotPlaceable)
class UDynamicObjectManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FObjectLoadedEvent m_onLoadFinishedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FObjectTrackerData> ObjectTracker;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UGameInstance* pGameInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ARandomEncounterActor* pRandomEncounter;
    
public:
    UDynamicObjectManager();
    UFUNCTION(BlueprintCallable)
    bool SpawnObjectByName(const FString& ObjectToSpawn);
    
    UFUNCTION(BlueprintCallable)
    AActor* SpawnDynamicObject(const FString& ObjectToSpawn, FDynamicObjectLoadInfo InSpawnParams);
    
    UFUNCTION(BlueprintCallable)
    void SetDynamicSpawningEnabled(bool bInEnableSpawning);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void ObjectLoaded();
    
    UFUNCTION(BlueprintCallable)
    bool LoadDynamicObject(const FString& ObjectToLoad);
    
    UFUNCTION(BlueprintCallable)
    bool IsObjectLoaded(const FString& ObjectToLoad);
    
    UFUNCTION(BlueprintCallable)
    static UDynamicObjectManager* Get();
    
    UFUNCTION(BlueprintCallable)
    FTransform FindValidLocation(FTransform InTransform, float Radius, float halfAngle);
    
    UFUNCTION()
    void DoDelayedSpawn(uint32 RequestID);
    
};

