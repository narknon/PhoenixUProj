#pragma once
#include "CoreMinimal.h"
#include "ArchitectGameInstance.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ESeasonEnum -FallbackName=ESeasonEnum
#include "EAutoSaveReason.h"
#include "ELoadingScreenLocation.h"
#include "ERespawnReason.h"
#include "ESeasonEnum.h"
#include "PlayerSpawnedDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "PhoenixGameInstance.generated.h"

class APawn;
class APlayerStart;
class UFastTravelManager;
class ULevel;
class UObject;
class UPhoenixPersistentAssets;
class UPhxDbRegistryTypeManager;
class UWorld;

UCLASS(Blueprintable, NonTransient)
class PHOENIX_API UPhoenixGameInstance : public UArchitectGameInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerSpawnedDelegate PlayerSpawnedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERespawnReason RespawnReason;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFastTravelManager> FastTravelManagerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowHoldPlayerUntilColliding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UPhoenixPersistentAssets> PersistentAssetsPaths;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> PersistentAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPhxDbRegistryTypeManager*> mRegistryTypeManagers;
    
public:
    UPhoenixGameInstance();
    UFUNCTION(BlueprintCallable)
    void UpdateSaveSpawnLocationEx(const FVector PlayerPostion, const FRotator PlayerOrientation);
    
    UFUNCTION(BlueprintCallable, Exec)
    void UpdateSaveSpawnLocation();
    
    UFUNCTION(BlueprintCallable, Exec)
    void UpdateChallengeSpawnLocation();
    
    UFUNCTION(BlueprintCallable)
    void StartNewGame(bool bInIsIntro);
    
    UFUNCTION(BlueprintCallable)
    void SetSaveSpawnLocationToPlayerStart(APlayerStart* InPlayerStart);
    
    UFUNCTION(BlueprintCallable)
    void SetPlayingFromFrontend();
    
    UFUNCTION(BlueprintCallable)
    void SetPlayingFromDeveloperMenu(bool bDeveloperMenu);
    
    UFUNCTION(BlueprintCallable)
    void SetPlayingDeveloperOverland(bool DeveloperOverland);
    
    UFUNCTION(BlueprintCallable)
    void SetPlayingDemoBuild();
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentLoadingScreenLocationByLevelName(const FName LevelName, const FString& PlayerStartTag);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentLoadingScreenLocation(const ELoadingScreenLocation Location);
    
    UFUNCTION(BlueprintCallable)
    bool SaveGameOptions();
    
    UFUNCTION(BlueprintCallable)
    bool PlayOverland();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PhoenixOpenLevelBySoftObjectPtr(const UObject* WorldContextObject, const TSoftObjectPtr<UWorld> Level, bool bAbsolute, const FString& OPTIONS);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PhoenixOpenLevel(const UObject* WorldContextObject, FName LevelName, bool bAbsolute, const FString& OPTIONS);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnDBVersionCheck(const int32 SaveVersion, const int32 SaveChangeList);
    
    UFUNCTION(BlueprintCallable)
    void OnAcceptEULA(bool Update);
    
    UFUNCTION(BlueprintCallable)
    void OnAboutToSaveGame();
    
    UFUNCTION(BlueprintCallable)
    bool NewGame(bool bInIsIntro);
    
    UFUNCTION(BlueprintCallable)
    bool LoadGameOptions();
    
    UFUNCTION(BlueprintCallable)
    bool LoadGame(const FString& SlotName, int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    void LevelShutdown();
    
    UFUNCTION(BlueprintCallable)
    void HoldPlayerUntilColliding(bool bFromHoverDrone);
    
    UFUNCTION(BlueprintCallable)
    bool HasLoadSaveData();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRotator GetSaveRotation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetSavePosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetSaveGameWorld() const;
    
    UFUNCTION(BlueprintCallable)
    FVector GetSafePlayerPosition();
    
    UFUNCTION(BlueprintCallable)
    bool GetPlayingFromFrontend();
    
    UFUNCTION(BlueprintCallable)
    bool GetPlayingFromDeveloperMenu();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPlayingDeveloperOverland() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetPlayingDemoBuild();
    
    UFUNCTION(BlueprintCallable)
    FVector GetPlayerPosition();
    
    UFUNCTION(BlueprintCallable)
    APawn* GetPlayerPawn();
    
    UFUNCTION(BlueprintCallable)
    FRotator GetPlayerOrientation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UPhoenixGameInstance* GetPhoenixGameInstancePure();
    
    UFUNCTION(BlueprintCallable)
    static UPhoenixGameInstance* GetPhoenixGameInstance();
    
    UFUNCTION(BlueprintCallable)
    FString GetCurrentWorldName();
    
    UFUNCTION(BlueprintCallable)
    ELoadingScreenLocation GetCurrentLoadingScreenLocation();
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameSaveHorcrux(const FString& SaveLabel);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameLoadImportedHorcruxToNewCharacter(int32 DestCharacterID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameLoadImportedHorcrux();
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameLoadHorcruxToNewCharacter(const FString& SaveLabel, int32 DestCharacterID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameLoadHorcrux(const FString& SaveLabel);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameLoadCloudSave(const FString& SlotName, bool bNewCharacter, int32 DestCharacterID);
    
    UFUNCTION(BlueprintCallable)
    void ForceSeasonUpdate(ESeasonEnum NewSeason);
    
    UFUNCTION(BlueprintCallable)
    void FadeReset();
    
    UFUNCTION(BlueprintCallable)
    void FadeOutToColor(FColor inFadeColor);
    
    UFUNCTION(BlueprintCallable)
    void FadeOut();
    
    UFUNCTION(BlueprintCallable)
    void FadeIn();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static ULevel* DetectLevelBelowCamera(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    bool ContinueGame();
    
    UFUNCTION(BlueprintCallable)
    void ClearPlayerHold();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ClearChallengeSpawnLocationFlag();
    
    UFUNCTION(BlueprintCallable)
    static bool AutoSaveGameData(const EAutoSaveReason Type);
    
};

