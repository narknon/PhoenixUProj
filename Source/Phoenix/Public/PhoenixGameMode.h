#pragma once
#include "CoreMinimal.h"
#include "Able_GameMode.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "AsyncLoadAssetListCompleteDelegate.h"
#include "PhoenixGameMode.generated.h"

class AActor;
class APhoenixGameMode;
class APlayerStart;
class UInstancedStaticMeshComponent;
class ULevelStreaming;
class UObject;
class UWorld;

UCLASS(Blueprintable, MinimalAPI, NonTransient)
class APhoenixGameMode : public AAble_GameMode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAsyncLoadAssetListComplete OnAsyncLoadAssetListComplete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APlayerStart* ProgrammaticPlayerStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> InterestPointActors;
    
public:
    APhoenixGameMode(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Exec)
    void YeeTest();
    
    UFUNCTION(BlueprintCallable, Exec)
    void VCGetContents(const FString& ContainerID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void UnregisterInterestPointActor(const FString& ActorName);
    
    UFUNCTION(BlueprintCallable)
    void SetProgrammaticPlayerStartInfo(const FVector& InLocation, const FRotator& InRotation, bool bForceUse);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetLocale(const FString& LocaleString);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveInstancedStaticMeshCollision(UInstancedStaticMeshComponent* InstancedMeshComponent, int32 InstanceIndex);
    
    UFUNCTION(BlueprintCallable, Exec)
    void RegisterInterestPointActor(const FString& InActorName, float InSpawnX, float InSpawnY, float InSpawnZ, bool bSpawnNewActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool PlayerStartedAtProgrammaticLocation() const;
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void OpenLevelByReference(const UObject* WorldContextObject, TSoftObjectPtr<UWorld> Level, bool bAbsolute, const FString& OPTIONS);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LootDrop(const FString& LootCategoryID, int32 Level);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static ULevelStreaming* GetStreamingLevelAva(const UObject* WorldContextObject, FName PackageName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetPlayerStartTag() const;
    
    UFUNCTION(BlueprintCallable)
    static APhoenixGameMode* GetPhoenixGameMode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetOptions();
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameStartMission();
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameFinishMission();
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameDBImport(const FString& ImportFilename);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameDBExport(const FString& ExportFilename);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameAbortMission();
    
    UFUNCTION(BlueprintCallable, Exec)
    void Dbg_ShowHUD();
    
    UFUNCTION(BlueprintCallable, Exec)
    void Dbg_HideHUD();
    
    UFUNCTION(BlueprintCallable)
    void ClearForceUseProgrammaticPlayerStart();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    void AsyncLoadAssetList(const UObject* WorldContextObject, const TArray<TSoftObjectPtr<UObject>>& AssetsToStream, int32& UniqueId);
    
};

