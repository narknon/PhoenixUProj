#include "CompanionManager.h"
#include "Templates/SubclassOf.h"

class AActor;
class AAmbulatory_Character;
class APawn;
class UAblAbility;
class UCompanionManager;
class UScheduledEntity;

bool UCompanionManager::TryCompanionTeleportBP(UScheduledEntity* ScheduledEntity, const FVector& TargetLocation, const FRotator& TargetRotation) {
    return false;
}

bool UCompanionManager::TryCompanionTeleportBehindPlayer() {
    return false;
}

void UCompanionManager::TryCompanionPlayerRescue() {
}

void UCompanionManager::StopPrimaryCompanionCustomAbility() {
}

void UCompanionManager::StopMovement(const bool InStopMovement) {
}

void UCompanionManager::StopCompanionForcedWaiting() {
}

void UCompanionManager::StartPrimaryCompanionCustomAbility(TSubclassOf<UAblAbility> Ability) {
}

void UCompanionManager::StartFadeOut() {
}

void UCompanionManager::StartFadeIn() {
}

void UCompanionManager::SetSystemicCompanionBP(const FString& Name, const bool bEnable) {
}

void UCompanionManager::SetCompanionSettingDataToConfigBP(const FString& Name) {
}

void UCompanionManager::SetCompanionSettingDataBP(const FString& Name, const FCompanionSettingData InCompanionSettingData) {
}

void UCompanionManager::SetCompanionIsIdleFlag(AActor* InCompanionActor, const bool InBCompanionIsIdle) {
}

void UCompanionManager::SetCompanionForcedWaitLocation(const FVector& InWaitLocation, const FVector& InWaitDirection) {
}

void UCompanionManager::SetCompanionBP(const FString& Name, const bool bEnable) {
}

void UCompanionManager::RestoreCompanionHealth() {
}

void UCompanionManager::PlayVoiceOverForPawn(const FString& VOEventName, APawn* Pawn) const {
}

bool UCompanionManager::PlayVoiceOver(const FString& VOEventName, EVoiceOverCompanionSelection Selection, EVoiceOverConditions Condition) const {
    return false;
}

void UCompanionManager::OnSaveGameLoaded() {
}

void UCompanionManager::OnPlayerEnterLeaveCompanionSettingsVolume(const AActor* Volume, const FCompanionVolumeSettings& Settings, bool bInside) {
}

void UCompanionManager::OnPawnEnterLeaveCompanionSettingsVolume(const AActor* Volume, const APawn* Pawn, const FCompanionVolumeSettings& Settings, bool bInside) {
}

void UCompanionManager::OnCompanionRemoved(AActor* Companion) {
}

void UCompanionManager::OnCompanionReady(const UScheduledEntity* companionScheduledEntity) {
}

void UCompanionManager::OnCompanionHealing(AActor* Instigator, float InHealthChange, AActor* TargetActor) {
}

void UCompanionManager::OnCompanionDismissed(FName CompanionName) {
}

void UCompanionManager::OnCompanionDied(AActor* Companion) {
}

void UCompanionManager::OnCompanionDamaged(AActor* InActor, AActor* InInstigator, float InDamage, const FHitResult& InHit) {
}

void UCompanionManager::OnCharacterTeleported(AAmbulatory_Character* TeleportedCharacter, FVector AmountDisplaced, FRotator AmountRotated) {
}

void UCompanionManager::OnAboutToSaveGame() {
}

bool UCompanionManager::MoveToLocation(const FVector InCharacterLocation, APawn* InCompanionPawn) {
    return false;
}

bool UCompanionManager::IsCompanionWaitingBP(const APawn* Pawn, FVector& WaitLocation) {
    return false;
}

bool UCompanionManager::IsCharacterCompanion(UScheduledEntity* entity) const {
    return false;
}

TArray<FName> UCompanionManager::IdentitiesAllowedToAddOnCompanion(const FName& InCompanionName) {
    return TArray<FName>();
}

bool UCompanionManager::HasPrimaryFollowingCompanion() const {
    return false;
}

bool UCompanionManager::HasPrimaryCompanion() const {
    return false;
}

bool UCompanionManager::HasCompanionToRescuePlayer() const {
    return false;
}

bool UCompanionManager::HasAnyCompanion() const {
    return false;
}

void UCompanionManager::HandleFleshLoaded(AActor* FleshActor) {
}

void UCompanionManager::HandleCompanionInteractionBP(const int32 Index) {
}

void UCompanionManager::HandleActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpluse, const FHitResult& Hit) {
}

TArray<FName> UCompanionManager::GetUnlockedSystemicCompanions() const {
    return TArray<FName>();
}

APawn* UCompanionManager::GetPrimaryCompanionPawn() const {
    return NULL;
}

FName UCompanionManager::GetPrimaryCompanionNameBP() {
    return NAME_None;
}

FString UCompanionManager::GetForcedCompanionName() const {
    return TEXT("");
}

TArray<FName> UCompanionManager::GetDisabledSystemicCompanions() const {
    return TArray<FName>();
}

bool UCompanionManager::GetCompanionSettingDataFromActorBP(const AActor* companionActor, FCompanionSettingData& OutCompanionSettingData) {
    return false;
}

bool UCompanionManager::GetCompanionSettingDataBP(const FString& Name, FCompanionSettingData& OutCompanionSettingData) {
    return false;
}

FName UCompanionManager::GetCompanionNameWithMostCompanionshipTime() {
    return NAME_None;
}

UCompanionManager* UCompanionManager::GetCompanionManager() {
    return NULL;
}

FString UCompanionManager::GetCompanionInteractionTextBP(AActor* interactionActor, const int32 Index) {
    return TEXT("");
}

bool UCompanionManager::GetCompanionFollowParamsBP(const APawn* Pawn, FCompanionFollowParams& Params) {
    return false;
}

TArray<FName> UCompanionManager::GetAllPossibleSystemicCompanions() const {
    return TArray<FName>();
}

bool UCompanionManager::GetActivePrimaryCompanionPawnAndName(APawn*& CompanionPawn, FName& OutCompanionName, bool bIsFemale) const {
    return false;
}

bool UCompanionManager::GetActivePrimaryCompanionPawn(APawn*& CompanionPawn) const {
    return false;
}

UCompanionManager* UCompanionManager::Get() {
    return NULL;
}

void UCompanionManager::DisableSystemicCompanionsForDungeons(const bool bDisable) {
}

bool UCompanionManager::ChooseLocation(APawn* InCompanionPawn, FVector& OutDestination) {
    return false;
}

void UCompanionManager::ChangeCompanionInvulnerableBP(const FName& InCompanionName, const bool InBMakeInvulnerable) {
}

bool UCompanionManager::CanSystemicallyCompanionable(const FName& InNPCName) {
    return false;
}

bool UCompanionManager::CanMoveCompanionBP(const APawn* Pawn, FCompanionFollowParams& Params) {
    return false;
}

void UCompanionManager::CancelAttackForAllCompanions() {
}

bool UCompanionManager::CanAddIdentity(const FName& InCompanionName) {
    return false;
}

bool UCompanionManager::AreSystemicCompanionsDisabled() const {
    return false;
}

void UCompanionManager::AddIdentityToCompanion(const FName& InCompanionName, const FName& InIdentityName) {
}

UCompanionManager::UCompanionManager() {
    this->Config = NULL;
}

