#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AchievementCategory.h"
#include "AchievementReward.h"
#include "EHomeworkType.h"
#include "KnowledgeAchievementResult.h"
#include "AchievementManager.generated.h"

class AActor;

UCLASS(Blueprintable)
class UAchievementManager : public UObject {
    GENERATED_BODY()
public:
    UAchievementManager();
    UFUNCTION(BlueprintCallable)
    void SetHomeworkWatcher(const TEnumAsByte<EHomeworkType> HomeworkType, const FString& HomeworkName, AActor* Caller, const bool bEnable, const bool AssertIfNotFound);
    
    UFUNCTION(BlueprintCallable)
    void SetAchievementWatcher(FName AchievementID, AActor* Caller, const bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    void ResetAchievement(FName AchievementID);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnNewGame();
    
    UFUNCTION(BlueprintCallable)
    bool IsHomeworkComplete(const TEnumAsByte<EHomeworkType> HomeworkType, const FString& HomeworkName, const bool AssertIfNotFound);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFieldGuideComplete();
    
    UFUNCTION(BlueprintCallable)
    bool IsAchievementComplete(FName AchievementID);
    
    UFUNCTION(BlueprintCallable)
    bool IsAchievementActive(FName AchievementID);
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleStatChanged(const FName StatID, const int32 Value, const int32 Delta);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UAchievementManager* GetPure();
    
    UFUNCTION(BlueprintCallable)
    TArray<FKnowledgeAchievementResult> GetKnowledgeChallengesForSubject(FName KnowledgeSubject);
    
    UFUNCTION(BlueprintCallable)
    int32 GetHomeworkInstances(const TEnumAsByte<EHomeworkType> HomeworkType, const FString& HomeworkName, const bool AssertIfNotFound);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFieldGuideCompletionPercentPerCategory(FAchievementCategory Category);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFieldGuideCompletionPercent();
    
    UFUNCTION(BlueprintCallable)
    int32 GetDelayedRewardsCount();
    
    UFUNCTION(BlueprintCallable)
    TArray<FKnowledgeAchievementResult> GetDelayedRewards();
    
    UFUNCTION(BlueprintCallable)
    FKnowledgeAchievementResult GetChallengeLevel(FName AchievementID);
    
    UFUNCTION(BlueprintCallable)
    TMap<FName, FAchievementCategory> GetChallengeCategories();
    
    UFUNCTION(BlueprintCallable)
    TArray<FKnowledgeAchievementResult> GetChalkboardChallengesForClass(FName ClassPrefix);
    
    UFUNCTION(BlueprintCallable)
    FName GetAchievementType(FName AchievementID);
    
    UFUNCTION(BlueprintCallable)
    int32 GetAchievementInstances(FName AchievementID);
    
    UFUNCTION(BlueprintCallable)
    int32 GetAchievementInstanceGoal(FName AchievementID);
    
    UFUNCTION(BlueprintCallable)
    static UAchievementManager* Get();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugCompleteAllChallenges();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugAwardChallenge(const FString& ChallengeID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugAwardAchievement(const FString& AchievementID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugAchievementShowState(const FString& AchievementID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugAchievementResetSteam();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugAchievementOneOfEach(const FString& AchievementID, const FString& ObjectName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugAchievementIncrease(const FString& AchievementID, int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    bool ClaimReward(FKnowledgeAchievementResult achievement, FAchievementReward reward);
    
    UFUNCTION(BlueprintCallable)
    void AwardOnUnlock(FName LockId);
    
    UFUNCTION(BlueprintCallable)
    void AwardOneTimeHomework(const TEnumAsByte<EHomeworkType> HomeworkType, const FString& HomeworkName, const bool AssertIfNotFound);
    
    UFUNCTION(BlueprintCallable)
    void AwardOneTimeAchievement(FName AchievementID, const bool CheckRulesFirst, const bool AssertIfNotOneTime);
    
    UFUNCTION(BlueprintCallable)
    bool ApplyWhitelistInstance(FName AchievementID, FName InstanceName);
    
    UFUNCTION(BlueprintCallable)
    bool ApplyOneOfEachInstance(FName AchievementID, FName InstanceName, bool isInternal);
    
    UFUNCTION(BlueprintCallable)
    void ApplyKnowledgeAction(FName KnowledgeSubject, FName KnowledgeAction, FName KnowledgeCategoryOverride);
    
    UFUNCTION(BlueprintCallable)
    void ApplyHomework(const TEnumAsByte<EHomeworkType> HomeworkType, const FString& HomeworkName, int32 Count, const bool AssertIfNotFound);
    
    UFUNCTION(BlueprintCallable)
    void ApplyAchievementIncrease(FName AchievementID, int32 Count, const bool CheckRulesFirst, const bool AssertIfNotAccumluate);
    
    UFUNCTION(BlueprintCallable)
    bool AnyDelayedRewards();
    
};

