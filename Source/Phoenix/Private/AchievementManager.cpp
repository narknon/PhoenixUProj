#include "AchievementManager.h"

class AActor;
class UAchievementManager;

void UAchievementManager::SetHomeworkWatcher(const TEnumAsByte<EHomeworkType> HomeworkType, const FString& HomeworkName, AActor* Caller, const bool bEnable, const bool AssertIfNotFound) {
}

void UAchievementManager::SetAchievementWatcher(FName AchievementID, AActor* Caller, const bool bEnable) {
}

void UAchievementManager::ResetAchievement(FName AchievementID) {
}

void UAchievementManager::OnSaveGameLoaded() {
}

void UAchievementManager::OnNewGame() {
}

bool UAchievementManager::IsHomeworkComplete(const TEnumAsByte<EHomeworkType> HomeworkType, const FString& HomeworkName, const bool AssertIfNotFound) {
    return false;
}

bool UAchievementManager::IsFieldGuideComplete() {
    return false;
}

bool UAchievementManager::IsAchievementComplete(FName AchievementID) {
    return false;
}

bool UAchievementManager::IsAchievementActive(FName AchievementID) {
    return false;
}

void UAchievementManager::HandleStatChanged(const FName StatID, const int32 Value, const int32 Delta) {
}

UAchievementManager* UAchievementManager::GetPure() {
    return NULL;
}

TArray<FKnowledgeAchievementResult> UAchievementManager::GetKnowledgeChallengesForSubject(FName KnowledgeSubject) {
    return TArray<FKnowledgeAchievementResult>();
}

int32 UAchievementManager::GetHomeworkInstances(const TEnumAsByte<EHomeworkType> HomeworkType, const FString& HomeworkName, const bool AssertIfNotFound) {
    return 0;
}

float UAchievementManager::GetFieldGuideCompletionPercentPerCategory(FAchievementCategory Category) {
    return 0.0f;
}

float UAchievementManager::GetFieldGuideCompletionPercent() {
    return 0.0f;
}

int32 UAchievementManager::GetDelayedRewardsCount() {
    return 0;
}

TArray<FKnowledgeAchievementResult> UAchievementManager::GetDelayedRewards() {
    return TArray<FKnowledgeAchievementResult>();
}

FKnowledgeAchievementResult UAchievementManager::GetChallengeLevel(FName AchievementID) {
    return FKnowledgeAchievementResult{};
}

TMap<FName, FAchievementCategory> UAchievementManager::GetChallengeCategories() {
    return TMap<FName, FAchievementCategory>();
}

TArray<FKnowledgeAchievementResult> UAchievementManager::GetChalkboardChallengesForClass(FName ClassPrefix) {
    return TArray<FKnowledgeAchievementResult>();
}

FName UAchievementManager::GetAchievementType(FName AchievementID) {
    return NAME_None;
}

int32 UAchievementManager::GetAchievementInstances(FName AchievementID) {
    return 0;
}

int32 UAchievementManager::GetAchievementInstanceGoal(FName AchievementID) {
    return 0;
}

UAchievementManager* UAchievementManager::Get() {
    return NULL;
}

void UAchievementManager::DebugCompleteAllChallenges() {
}

void UAchievementManager::DebugAwardChallenge(const FString& ChallengeID) {
}

void UAchievementManager::DebugAwardAchievement(const FString& AchievementID) {
}

void UAchievementManager::DebugAchievementShowState(const FString& AchievementID) {
}

void UAchievementManager::DebugAchievementResetSteam() {
}

void UAchievementManager::DebugAchievementOneOfEach(const FString& AchievementID, const FString& ObjectName) {
}

void UAchievementManager::DebugAchievementIncrease(const FString& AchievementID, int32 Amount) {
}

bool UAchievementManager::ClaimReward(FKnowledgeAchievementResult achievement, FAchievementReward reward) {
    return false;
}

void UAchievementManager::AwardOnUnlock(FName LockId) {
}

void UAchievementManager::AwardOneTimeHomework(const TEnumAsByte<EHomeworkType> HomeworkType, const FString& HomeworkName, const bool AssertIfNotFound) {
}

void UAchievementManager::AwardOneTimeAchievement(FName AchievementID, const bool CheckRulesFirst, const bool AssertIfNotOneTime) {
}

bool UAchievementManager::ApplyWhitelistInstance(FName AchievementID, FName InstanceName) {
    return false;
}

bool UAchievementManager::ApplyOneOfEachInstance(FName AchievementID, FName InstanceName, bool isInternal) {
    return false;
}

void UAchievementManager::ApplyKnowledgeAction(FName KnowledgeSubject, FName KnowledgeAction, FName KnowledgeCategoryOverride) {
}

void UAchievementManager::ApplyHomework(const TEnumAsByte<EHomeworkType> HomeworkType, const FString& HomeworkName, int32 Count, const bool AssertIfNotFound) {
}

void UAchievementManager::ApplyAchievementIncrease(FName AchievementID, int32 Count, const bool CheckRulesFirst, const bool AssertIfNotAccumluate) {
}

bool UAchievementManager::AnyDelayedRewards() {
    return false;
}

UAchievementManager::UAchievementManager() {
}

