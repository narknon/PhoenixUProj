#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ESaveType.h"
#include "SaveGameInfo.h"
#include "EAutoSaveReason.h"
#include "EDifficulty.h"
#include "ESaveBlockReason.h"
#include "OnDifficultyChangedDelegate.h"
#include "OnPostGameLoadDelegate.h"
#include "OnPostGameSaveDelegate.h"
#include "OnPreGameLoadDelegate.h"
#include "OnPreGameSaveDelegate.h"
#include "SaveManager.generated.h"

class USaveManager;

UCLASS(Blueprintable)
class USaveManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPreGameSave OnPreGameSave;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPostGameSave OnPostGameSave;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPreGameLoad OnPreGameLoad;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPostGameLoad OnPostGameLoad;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDifficultyChanged OnGameDifficultyChanged;
    
    USaveManager();
    UFUNCTION(BlueprintCallable)
    static bool UserSaveGameData();
    
    UFUNCTION(BlueprintCallable)
    static bool UpdateActiveCharacterProfilePresets(TArray<FName> CharacterPresets);
    
    UFUNCTION(BlueprintCallable)
    static bool UpdateActiveCharacterProfileClothes(TArray<FName> CharacterClothes, const FString& AllGearTags);
    
    UFUNCTION(BlueprintCallable, Exec)
    void UnblockSaveGames();
    
    UFUNCTION(BlueprintCallable)
    static void SetPrimaryUserIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    static bool SetCurrentVoicePitch(int32 VoicePitch);
    
    UFUNCTION(BlueprintCallable)
    static bool SetCurrentRigGender(const FString& RigGender);
    
    UFUNCTION(BlueprintCallable)
    static bool SetCurrentGameDifficulty(EDifficulty Difficulty);
    
    UFUNCTION(BlueprintCallable)
    static bool SaveCurrentVoicePitch(int32 VoicePitch);
    
    UFUNCTION(BlueprintCallable)
    static bool ResetCurrentGameDifficulty();
    
    UFUNCTION(BlueprintCallable)
    static void RemoveBlockRequest(const ESaveBlockReason Reason, const bool bRemoveAll);
    
    UFUNCTION(BlueprintCallable)
    static bool IsSaveGameBlocked();
    
    UFUNCTION(BlueprintCallable)
    static bool IsAutoSaveGameBlocked(const EAutoSaveReason Reason);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetPrimaryUserIndex();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetCurrentVoicePitch();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetCurrentGameDifficulty(EDifficulty& Difficulty);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FSaveGameInfo> GetAllUserEntries();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FSaveGameInfo> GetAllSavesOfType_Unsorted_IncludeEmptyUserSaves(ESaveType SaveType, int32 PlayerId);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FSaveGameInfo> GetAllSavesOfType(ESaveType SaveType, int32 PlayerId);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FSaveGameInfo> GetAllAutoEntries();
    
    UFUNCTION(BlueprintCallable)
    static USaveManager* Get();
    
    UFUNCTION(BlueprintCallable)
    void ExecutePreGameSave();
    
    UFUNCTION(BlueprintCallable)
    void ExecutePreGameLoad();
    
    UFUNCTION(BlueprintCallable)
    void ExecutePostGameSave();
    
    UFUNCTION(BlueprintCallable)
    void ExecutePostGameLoad();
    
    UFUNCTION(BlueprintCallable)
    void ExecuteCombatEnds();
    
    UFUNCTION(BlueprintCallable)
    void ExecuteCombatBegins();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DumpSaveGameBlocks();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ClearSaveGameBlocks();
    
    UFUNCTION(BlueprintCallable)
    static bool BP_DoesCharacterExistYet();
    
    UFUNCTION(BlueprintCallable)
    static bool BP_CreateCharacter(const FString& CharacterName, const FString& CharacterHouse);
    
    UFUNCTION(BlueprintCallable)
    static void BP_ContinuePrevSessionClock();
    
    UFUNCTION(BlueprintCallable)
    static bool BP_AutoSaveGame(EAutoSaveReason Reason);
    
    UFUNCTION(BlueprintCallable, Exec)
    void BlockSaveGames();
    
    UFUNCTION(BlueprintCallable)
    static bool AutoSaveGameData(const EAutoSaveReason Type, bool bCollectSaveData);
    
    UFUNCTION(BlueprintCallable)
    static bool AutoSaveFlush(bool bAsynchronous);
    
    UFUNCTION(BlueprintCallable)
    static void AddBlockRequest(const ESaveBlockReason Reason);
    
};

