#include "CharacterStateInfo.h"
#include "Templates/SubclassOf.h"

class AActor;
class UBonySkeletonComponent;
class UCharacterStateInfo;

bool UCharacterStateInfo::WereSameTeam(const AActor* ActorPtr1, const AActor* ActorPtr2) {
    return false;
}

bool UCharacterStateInfo::WereAllies(const AActor* ActorPtr1, const AActor* ActorPtr2) {
    return false;
}

bool UCharacterStateInfo::WasSameTeam(const AActor* ActorPtr) const {
    return false;
}

bool UCharacterStateInfo::WasAlly(const AActor* ActorPtr) const {
    return false;
}

void UCharacterStateInfo::StopIntervalHealthAdjust() {
}

void UCharacterStateInfo::StartIntervalHealthAdjust(float Interval, float Duration, float DeltaAmount) {
}

void UCharacterStateInfo::SetVulnerable(bool bInIsVulnerable) {
}

void UCharacterStateInfo::SetTeammateAllyOverride(bool bOverride) {
}

void UCharacterStateInfo::SetTeamInteractionBetween(const AActor* InteractorActorPtr, const FName& InteracteeTeam, const FName& InInteraction, int32 Priority) {
}

void UCharacterStateInfo::SetTeamInteraction(const FName& InteracteeTeam, const FName& InInteraction, int32 Priority) {
}

void UCharacterStateInfo::SetTeam(const FName& InTeam) {
}

void UCharacterStateInfo::SetRegenerationRate(float Rate) {
}

void UCharacterStateInfo::SetProtegoActive(bool bProtegoActive) {
}

void UCharacterStateInfo::SetProtected(bool bInProtected) {
}

void UCharacterStateInfo::SetOverrideNearDeathRecoverTime(float Time) {
}

void UCharacterStateInfo::SetLootable(bool bInLootable) {
}

void UCharacterStateInfo::SetIsAsleep(bool bInAsleep) {
}

void UCharacterStateInfo::SetInvincible(bool bInIsInvincible) {
}

void UCharacterStateInfo::SetInteractionBetween(const AActor* InteractorActorPtr, const AActor* InteracteeActorPtr, const FName& InInteraction, int32 Priority) {
}

void UCharacterStateInfo::SetInteraction(const AActor* InteracteeActorPtr, const FName& InInteraction, int32 Priority) {
}

void UCharacterStateInfo::SetImperiusInstigator(AActor* InInstigatorPtr) {
}

void UCharacterStateInfo::SetImperiusCharTakesFullDamage(bool TakesFullDamage) {
}

void UCharacterStateInfo::SetIgnoreProtego(float Time) {
}

void UCharacterStateInfo::SetIgnoreAllyAttacks(bool Ignore) {
}

void UCharacterStateInfo::SetHealthThresholdArray(const TArray<FHealthThreshold>& HealthThresholdArray) {
}

void UCharacterStateInfo::SetDamageable(bool bAttackable) {
}

void UCharacterStateInfo::SetBlockingActor(AActor* InBlockingActor) {
}

void UCharacterStateInfo::SetAttackable(bool bAttackable) {
}

void UCharacterStateInfo::SetActorVulnerable(const AActor* InActor, bool bInIsVulnerable) {
}

void UCharacterStateInfo::SetActorToTeam(const AActor* DestActor, const AActor* SourceActor) {
}

void UCharacterStateInfo::SetActorInvincible(const AActor* InActor, bool bInIsInvincible) {
}

void UCharacterStateInfo::SetActorAttackable(const AActor* InActor, bool bInAttackable) {
}

void UCharacterStateInfo::SetActiveAuthorityFigure(bool bActive) {
}

void UCharacterStateInfo::RestoreLastTeam() {
}

void UCharacterStateInfo::RestoreInitialTeam() {
}

void UCharacterStateInfo::RestoreHealthToMax(const bool bRemoveTAK) {
}

void UCharacterStateInfo::RestoreActorToLastTeam(const AActor* DestActor) {
}

void UCharacterStateInfo::RestoreActorToInitialTeam(const AActor* DestActor) {
}

void UCharacterStateInfo::ResetTeamInteractionBetween(const AActor* InteractorActorPtr, const FName& InteracteeTeam) {
}

void UCharacterStateInfo::ResetTeamInteraction(const FName& InteracteeTeam) {
}

void UCharacterStateInfo::ResetInteractionBetween(const AActor* InteractorActorPtr, const AActor* InteracteeActorPtr) {
}

void UCharacterStateInfo::ResetInteraction(const AActor* InteracteeActorPtr) {
}

void UCharacterStateInfo::ResetAllInteractionsFrom(const AActor* InteractorActorPtr) {
}

void UCharacterStateInfo::ResetAllInteractions() {
}

bool UCharacterStateInfo::IsVulnerable() const {
    return false;
}

bool UCharacterStateInfo::IsUnaware(const AActor* Source, const AActor* Target) {
    return false;
}

bool UCharacterStateInfo::IsSameTeam(const AActor* ActorPtr) const {
    return false;
}

bool UCharacterStateInfo::IsProtegoActive() const {
    return false;
}

bool UCharacterStateInfo::IsProtected() const {
    return false;
}

bool UCharacterStateInfo::IsPlayerSpawnableAlly(const AActor* ActorPtr) {
    return false;
}

bool UCharacterStateInfo::IsLootable() const {
    return false;
}

bool UCharacterStateInfo::IsInvincible() const {
    return false;
}

bool UCharacterStateInfo::IsIgnoringProtego() const {
    return false;
}

bool UCharacterStateInfo::IsDueling() const {
    return false;
}

bool UCharacterStateInfo::IsDamageable() const {
    return false;
}

bool UCharacterStateInfo::IsAttackable() const {
    return false;
}

bool UCharacterStateInfo::IsAsleep() const {
    return false;
}

bool UCharacterStateInfo::IsActorVulnerable(const AActor* InActor) {
    return false;
}

bool UCharacterStateInfo::IsActorInvincible(const AActor* InActor) {
    return false;
}

bool UCharacterStateInfo::IsActorAttackable(const AActor* InActor) {
    return false;
}

bool UCharacterStateInfo::IsActiveAuthorityFigure() const {
    return false;
}

bool UCharacterStateInfo::ImmuneToFinisherDeath() const {
    return false;
}

bool UCharacterStateInfo::HasInteractionBetween(const AActor* InteractorActorPtr, const AActor* InteracteeActorPtr) {
    return false;
}

bool UCharacterStateInfo::HasInteraction(const AActor* InteracteeActorPtr) const {
    return false;
}

bool UCharacterStateInfo::HasChangedTeams() const {
    return false;
}

FName UCharacterStateInfo::GetTeamInteraction(const AActor* InteracteeActorPtr, const FName& Team) const {
    return NAME_None;
}

FName UCharacterStateInfo::GetTeam() const {
    return NAME_None;
}

float UCharacterStateInfo::GetRegenerationRate() const {
    return 0.0f;
}

FString UCharacterStateInfo::GetObjectClassName(const AActor* InActor) {
    return TEXT("");
}

float UCharacterStateInfo::GetNumberOfHappyBeasts() {
    return 0.0f;
}

FName UCharacterStateInfo::GetLastTeam() const {
    return NAME_None;
}

FName UCharacterStateInfo::GetInteractionBetween(const AActor* InteractorActorPtr, const AActor* InteracteeActorPtr) {
    return NAME_None;
}

FName UCharacterStateInfo::GetInteraction(const AActor* InteracteeActorPtr) const {
    return NAME_None;
}

FName UCharacterStateInfo::GetInitialTeam() const {
    return NAME_None;
}

AActor* UCharacterStateInfo::GetImperiusInstigator() const {
    return NULL;
}

bool UCharacterStateInfo::GetImperiusCharTakesFullDamage() const {
    return false;
}

bool UCharacterStateInfo::GetIgnoreAllyAttacks() const {
    return false;
}

TArray<FHealthThreshold> UCharacterStateInfo::GetHealthThresholdArray() {
    return TArray<FHealthThreshold>();
}

float UCharacterStateInfo::GetGameEventRadius() const {
    return 0.0f;
}

float UCharacterStateInfo::GetEvilEffectiveness() const {
    return 0.0f;
}

FName UCharacterStateInfo::GetEnemyInteractionWith(const AActor* InteractorActorPtr) {
    return NAME_None;
}

FName UCharacterStateInfo::GetEnemyInteraction(FName InInteractorTeam) const {
    return NAME_None;
}

UCharacterStateInfo* UCharacterStateInfo::GetCharacterStateInfo(const AActor* InActor) {
    return NULL;
}

TSubclassOf<UBonySkeletonComponent> UCharacterStateInfo::GetBonySkeleton() const {
    return NULL;
}

AActor* UCharacterStateInfo::GetBlockingActor() {
    return NULL;
}

FName UCharacterStateInfo::GetActorTeam(const AActor* DestActor) {
    return NAME_None;
}

FName UCharacterStateInfo::GetActorSubtypeID(const AActor* ActorPtr) {
    return NAME_None;
}

void UCharacterStateInfo::EndNearDeathKneel() {
}

void UCharacterStateInfo::ClearOverrideNearDeathRecoverTime() {
}

void UCharacterStateInfo::ClearIgnoreProtego() {
}

void UCharacterStateInfo::ChangeTeam(const FName& InTeam) {
}

void UCharacterStateInfo::ChangeActorToTeam(const AActor* DestActor, const AActor* SourceActor) {
}

bool UCharacterStateInfo::CanHitTarget(const AActor* Attacker, const AActor* Target) {
    return false;
}

bool UCharacterStateInfo::AreSameTeam(const AActor* ActorPtr1, const AActor* ActorPtr2) {
    return false;
}

bool UCharacterStateInfo::AreAllies(const AActor* ActorPtr1, const AActor* ActorPtr2) {
    return false;
}

UCharacterStateInfo::UCharacterStateInfo() {
    this->BlockingActor = NULL;
}

