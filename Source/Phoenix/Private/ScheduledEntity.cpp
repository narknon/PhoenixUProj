#include "ScheduledEntity.h"
#include "Templates/SubclassOf.h"

class AActor;
class ABase_Character;
class AFlyingBroom;
class APawn;
class ASocialReasoning;
class AStation;
class UAblAbility;
class UFlyingBroomPhysics;
class UObject;
class UPathComponent;

bool UScheduledEntity::StartSchedulingOverride(const bool InValue, ESchedulingPriority InPriority, const UObject* InProvider, const bool bInProdcessValue, const bool bInForceExit, const bool bInProcessSchedule) {
    return false;
}

void UScheduledEntity::StartPrecachingFlesh(ESEPrecacheFleshPriority InPriority, UObject* InCaller, float InPrecacheDistance, bool bInAutoFleshLock) {
}

bool UScheduledEntity::SetFlesh(ABase_Character* InFlesh) {
    return false;
}

void UScheduledEntity::SetCurrentActorToAggro(const FName InRequiredTeam, const bool bEnableCombat) {
}

void UScheduledEntity::SetCompanionHighLOD(bool bHighLOD) {
}

void UScheduledEntity::RequestHighLOD() {
}

void UScheduledEntity::PerformTask_WaitForTime(const float InTime, const FString& InLocation) {
}

bool UScheduledEntity::PerformTask_WaitForPlayerIsComplete() {
    return false;
}

void UScheduledEntity::PerformTask_WaitForPlayer(const float InDistance, bool InbOrientTowardsPlayer) {
}

bool UScheduledEntity::PerformTask_TeleportToTransform(const FTransform& InTransform) {
    return false;
}

bool UScheduledEntity::PerformTask_TeleportToStation(const AStation* InStation, const bool bInInteract, const FString& InSocialAction, const int32 InConnectionIndex, const float InStationDurationOverride, bool InSkipValidation) {
    return false;
}

bool UScheduledEntity::PerformTask_TeleportToLocation(const FVector& InLocation) {
    return false;
}

void UScheduledEntity::PerformTask_StopLumosOnNPC(bool bSuccess, bool bTimeout) {
}

void UScheduledEntity::PerformTask_StartLumosOnNPC(float Timeout, int32 InSpellLevel) {
}

void UScheduledEntity::PerformTask_StartCustomTask_NoLocation() {
}

void UScheduledEntity::PerformTask_ReparoFinished(uint8 InAction) {
}

void UScheduledEntity::PerformTask_RemoveActivePerformTask() {
}

bool UScheduledEntity::PerformTask_PlaceAtTransform(const FTransform& InTransform) {
    return false;
}

bool UScheduledEntity::PerformTask_PlaceAtLocation(const FVector& InLocation) {
    return false;
}

bool UScheduledEntity::PerformTask_MoveToStation(const AStation* InStation, const FName InActionName, const bool bInInteract, const float InForceSpeed, const int32 InConnectionIndex, const float InStationDurationOverride) {
    return false;
}

void UScheduledEntity::PerformTask_MoveToLocation(const FVector& InLocation, const float InForceSpeed, const bool InBTriggerNextActivity, const float InRadius, const UPathComponent* InPath) {
}

AFlyingBroom* UScheduledEntity::PerformTask_MountBroomWithFlightData(const TSubclassOf<AFlyingBroom> FlyingBroomClass, UFlyingBroomPhysics* StudentFlightData) {
    return NULL;
}

AFlyingBroom* UScheduledEntity::PerformTask_MountBroom(const TSubclassOf<AFlyingBroom> FlyingBroomClass) {
    return NULL;
}

void UScheduledEntity::PerformTask_FollowActor(AActor* InFollowActor, const float InForceSpeed) {
}

void UScheduledEntity::PerformTask_FinishCustomTask_NoLocation() {
}

void UScheduledEntity::PerformTask_DismountBroom() {
}

void UScheduledEntity::PerformTask_CustomSpellFinished(uint8 InAction) {
}

void UScheduledEntity::PerformTask_CastReparo(AActor* TargetPtr, float Timeout) {
}

void UScheduledEntity::PerformTask_CastCustomSpell(AActor* TargetPtr, float Timeout) {
}

bool UScheduledEntity::PerformTask_ApparateOutActivity() {
    return false;
}

bool UScheduledEntity::PerformTask_ApparateOut(const TSubclassOf<UAblAbility> InAblAbility) {
    return false;
}

bool UScheduledEntity::PerformTask_ApparateIn(const TSubclassOf<UAblAbility> InAblAbility) {
    return false;
}

void UScheduledEntity::PerformTask_ApparateFinishedActivity() {
}

void UScheduledEntity::PerformTask_ApparateFinished() {
}

void UScheduledEntity::PawnOverlapBegin(AActor* InSelf, AActor* InOther) {
}

void UScheduledEntity::Pause(bool bInPause) {
}

bool UScheduledEntity::IsWorldEventReleasedHobo() {
    return false;
}

bool UScheduledEntity::IsWorldEventHobo() {
    return false;
}

bool UScheduledEntity::IsWaitingForStation() {
    return false;
}

bool UScheduledEntity::IsStudent() {
    return false;
}

bool UScheduledEntity::IsSplineHobo() {
    return false;
}

bool UScheduledEntity::IsSeatFillerHobo() {
    return false;
}

bool UScheduledEntity::IsSceneRigHobo() {
    return false;
}

bool UScheduledEntity::IsInTransit() {
    return false;
}

bool UScheduledEntity::IsInPlayerInteraction() {
    return false;
}

bool UScheduledEntity::IsHobo() {
    return false;
}

bool UScheduledEntity::IsGhost() {
    return false;
}

bool UScheduledEntity::IsGeneralHobo() {
    return false;
}

bool UScheduledEntity::IsEnabled() {
    return false;
}

void UScheduledEntity::GetUpcomingActivity(bool& ActivityIsValid, FScheduleEntry& UpcomingActivity) {
}

ASocialReasoning* UScheduledEntity::GetSocialReasoning() {
    return NULL;
}

void UScheduledEntity::GetMinutesToUpcomingActivity(bool& ActivityIsValid, int32& MinutesToUpcomingActivity) {
}

FVector UScheduledEntity::GetLocation() {
    return FVector{};
}

void UScheduledEntity::GetGoalStatus(E_Goal::Type GoalType, FGoalStatus& GoalStatus) {
}

void UScheduledEntity::GetGoalActivity(E_Goal::Type GoalType, bool& ActivityIsValid, FScheduleEntry& RequestedActivity) {
}

APawn* UScheduledEntity::GetFlesh() const {
    return NULL;
}

float UScheduledEntity::GetExcessTravelTime(float InDeltaTime) {
    return 0.0f;
}

ABase_Character* UScheduledEntity::GetBaseCharacter() const {
    return NULL;
}

bool UScheduledEntity::FinishSchedulingOverride(ESchedulingPriority InPriority, const UObject* InProvider, const bool bInProcessValue, const bool bInForceExit, const bool bInProcessSchedule) {
    return false;
}

void UScheduledEntity::EndPrecachingFlesh(ESEPrecacheFleshPriority InPriority, UObject* InCaller, bool bInAutoFleshLock) {
}

void UScheduledEntity::EnableSocialControl(const bool InEnable) {
}

bool UScheduledEntity::EnableScheduling(const bool InEnable, const bool bInForceExit, const bool bInProcessSchedule) {
    return false;
}

void UScheduledEntity::DontAllowBTShutdown(ESEAllowBTShutdownPriority InPriority, UObject* InCaller) {
}

void UScheduledEntity::DialogCompleteCallback() {
}

bool UScheduledEntity::CurrentlyInFlesh() {
    return false;
}

void UScheduledEntity::CollisionResponseEnded(ASocialReasoning* SocialReasoning, FName SocialAction) {
}

void UScheduledEntity::CanAllowBTShutdown(ESEAllowBTShutdownPriority InPriority, UObject* InCaller) {
}

void UScheduledEntity::AddThinkNowEvent(const FString& InText, float InDelayLow, float InDelayHigh, bool bInAllowBTShutdown) {
}

bool UScheduledEntity::AbandonStations(EStationExitCallBack InExitCallback) {
    return false;
}

UScheduledEntity::UScheduledEntity() {
    this->FollowCamActor = NULL;
    this->NavPathController = NULL;
    this->SplinePathController = NULL;
    this->DefaultController = NULL;
    this->ScheduledEntitySocialReasoning = NULL;
    this->PathComponent_PT = NULL;
    this->StationComponent_MTS = NULL;
}

