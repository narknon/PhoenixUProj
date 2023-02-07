#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CharacterSaveGameInfo.h"
#include "CrossGenSaveDataCompleteDelegate.h"
#include "ESaveType.h"
#include "OnDBVersionCheckDelegate.h"
#include "OnGameToBeSavedDelegate.h"
#include "OnSaveGameCompleteDelegate.h"
#include "OnSaveGameLoadedDelegate.h"
#include "PostCharacterDeletedDelegate.h"
#include "PreCharacterDeletedDelegate.h"
#include "PreSaveLoadedDelegate.h"
#include "SaveGameInfo.h"
#include "PersistentData.generated.h"

class UPersistentData;

UCLASS(Blueprintable)
class PERSISTENTDATA_API UPersistentData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGameToBeSaved OnGameToBeSaved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGameToBeSaved OnPostGameToBeSaved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPreSaveLoaded PreSaveLoaded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSaveGameLoaded OnSaveGameLoaded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPreCharacterDeleted PreCharacterDeleted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDBVersionCheck OnDBVersionCheck;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSaveGameComplete OnSaveGameComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPostCharacterDeleted OnCharacterDeleted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCrossGenSaveDataComplete OnCrossGenSaveDataComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCrossGenSaveDataComplete OnAllCrossGenSaveDataComplete;
    
    UPersistentData();
    UFUNCTION(BlueprintCallable)
    static bool UpdatePlayableCharacterVoice(int32 CharacterID, const FString& CharacterVoice);
    
    UFUNCTION(BlueprintCallable)
    static bool UpdatePlayableCharacterPronoun(int32 CharacterID, const FString& CharacterPronoun);
    
    UFUNCTION(BlueprintCallable)
    static bool UpdatePlayableCharacterPresets(int32 CharacterID, TArray<FName> CharacterPresets);
    
    UFUNCTION(BlueprintCallable)
    static bool UpdatePlayableCharacterName(int32 CharacterID, const FString& CharacterName);
    
    UFUNCTION(BlueprintCallable)
    static bool UpdatePlayableCharacterLevel(int32 CharacterID, int32 CharacterLevel);
    
    UFUNCTION(BlueprintCallable)
    static bool UpdatePlayableCharacterHouse(int32 CharacterID, const FString& CharacterHouse);
    
    UFUNCTION(BlueprintCallable)
    static bool UpdatePlayableCharacterGender(int32 CharacterID, const FString& CharacterGender);
    
    UFUNCTION(BlueprintCallable)
    static bool UpdatePlayableCharacterClothes(int32 CharacterID, TArray<FName> CharacterClothes, const FString& AllGearTags);
    
    UFUNCTION(BlueprintCallable)
    static bool SaveGameDataOfType(ESaveType SaveType, int32 CharacterID, const FString& LocationName, const FString& MissionData, bool bCollectSaveData);
    
    UFUNCTION(BlueprintCallable)
    static bool SaveGameDataInSlot(const FString& SlotName, ESaveType SaveType, int32 CharacterID, const FString& LocationName, const FString& MissionData, bool bCollectSaveData, const FString& CloudLabel);
    
    UFUNCTION(BlueprintCallable)
    static bool RemoveSaveInSlot(const FString& SlotName, int32 CharacterID);
    
    UFUNCTION(BlueprintCallable)
    static bool RemovePlayableCharacter(int32 CharacterID, bool bSaveFileListAsync);
    
    UFUNCTION(BlueprintCallable)
    static bool RemoveAllSavesForCharacter(int32 CharacterID);
    
    UFUNCTION(BlueprintCallable)
    static bool RemoveAllSaveData();
    
    UFUNCTION(BlueprintCallable)
    void OnCrossGenSaveDataLoaded(bool Result);
    
    UFUNCTION(BlueprintCallable)
    static bool LoadLastSaveOfType(ESaveType SaveType, int32 CharacterID);
    
    UFUNCTION(BlueprintCallable)
    static bool LoadGameDataInSlot(const FString& SlotName, int32 CharacterID);
    
    UFUNCTION(BlueprintCallable)
    static bool LoadCrossGenSaveDataInSlot(const FString& SlotName, const FString& OldSlotName);
    
    UFUNCTION(BlueprintCallable)
    void LoadCrossGenSaveData(int32 fromCharacterIndex, int32 toCharacterIndex, bool SaveFileList);
    
    UFUNCTION(BlueprintCallable)
    void LoadAllCrossGenSaveData();
    
    UFUNCTION(BlueprintCallable)
    static bool HasEverLaunchedGame();
    
    UFUNCTION(BlueprintCallable)
    static bool HasCreatedPlayableCharacter();
    
    UFUNCTION(BlueprintCallable)
    static bool HasCompletedIntro();
    
    UFUNCTION(BlueprintCallable)
    static bool GetWizardingWorldData(const FString& Attribute, FString& OutValue);
    
    UFUNCTION(BlueprintCallable)
    static FCharacterSaveGameInfo GetPlayableCharacter(int32 CharacterID);
    
    UFUNCTION(BlueprintCallable)
    static FCharacterSaveGameInfo GetLastLoadedPlayableCharacter();
    
    UFUNCTION(BlueprintCallable)
    static bool GetIsPlayableCharacterUsed(int32 CharacterID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UPersistentData* GetInstance();
    
    UFUNCTION(BlueprintCallable)
    static uint8 GetDefaultDifficulty();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetCurrentPlayerID();
    
    UFUNCTION(BlueprintCallable)
    static FCharacterSaveGameInfo GetCurrentPlayableCharacter();
    
    UFUNCTION(BlueprintCallable)
    static FString GetCrossGenPlayableCharacterName(const FCharacterSaveGameInfo& CharacterInfo);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FCharacterSaveGameInfo> GetCrossGenCharacterList();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FSaveGameInfo> GetAvailableCrossGenSaveData();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FCharacterSaveGameInfo> GetAllPlayableCharacters();
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameUserSave(int32 CharacterID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameTestSaveGameList(int32 CharacterID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameRemoveSaveSlot(const FString& SlotName, int32 CharacterID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameRemovePlayableCharacter(int32 CharacterID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GamePurgeAllSaveData();
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameLogSaveGameList(int32 CharacterID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameLogSaveDirList();
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameLogPlayableCharacters();
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameLoadLastUserSave(int32 CharacterID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameLoadLastSave(int32 CharacterID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameLoadLastAutoSave(int32 CharacterID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameLoad(int32 CharacterID, const FString& SaveNameOverride);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameDBSave(const FString& SaveFileNameOverride);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameDBLoad(const FString& SaveFileNameOverride);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameCreatePlayableCharacter(const FString& CharacterName, const FString& CharacterHouse);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GameAutoSave(int32 CharacterID);
    
    UFUNCTION(BlueprintCallable)
    static void FlushAutoSaveCacheIfNecessary();
    
    UFUNCTION(BlueprintCallable)
    static bool DoesCrossGenSaveDataExist();
    
    UFUNCTION(BlueprintCallable, Exec)
    void CrossGenSaveDataLog();
    
    UFUNCTION(BlueprintCallable, Exec)
    void CrossGenSaveDataLoad(int32 fromCharacterIndex, int32 toCharacterIndex);
    
    UFUNCTION(BlueprintCallable)
    static int32 CreatePlayableCharacter(const FString& CharacterName, const FString& CharacterHouse, const FString& CharacterUID, const FString& CharacterVoice, const FString& CharacterPronoun);
    
    UFUNCTION(BlueprintCallable)
    static void CreateHorcruxSlot();
    
    UFUNCTION(BlueprintCallable)
    static void CompletedIntro();
    
    UFUNCTION(BlueprintCallable)
    static bool BP_SaveGame(const FString& LocationName);
    
    UFUNCTION(BlueprintCallable)
    static bool BP_DoesCharacterExistYet();
    
    UFUNCTION(BlueprintCallable)
    static bool BP_CreateCharacter(const FString& CharacterName, const FString& CharacterHouse);
    
    UFUNCTION(BlueprintCallable)
    static bool AsyncRemovePlayableCharacter(int32 CharacterID);
    
};

