#include "ObjectStateInfo.h"
#include "Templates/SubclassOf.h"

class AActor;
class AMunitionType_Base;
class UAkAudioEvent;
class UAkComponent;
class UGeometryCollection;
class UMaterialPropertyData;
class UObject;
class UObjectStateInfoData;
class UParticleSystem;
class UPhoenixPhysicalMaterial;
class UPrimitiveComponent;
class UStateEffectComponent;
class UStaticMesh;
class UVelocityTrackerComponent;

bool UObjectStateInfo::WillRevealThruWalls() const {
    return false;
}

bool UObjectStateInfo::WillNearDeathKneel() const {
    return false;
}

bool UObjectStateInfo::WasOnFireWhenKilled() const {
    return false;
}

void UObjectStateInfo::UpdateUsability() {
}

void UObjectStateInfo::UpdateActivation() {
}

bool UObjectStateInfo::Unlock(float Value) {
    return false;
}

bool UObjectStateInfo::TreatAsCharacterForDamage() const {
    return false;
}

bool UObjectStateInfo::Thaw() {
    return false;
}

bool UObjectStateInfo::TakeDamageFromCharacterCollisions() const {
    return false;
}

bool UObjectStateInfo::ShouldCreateCrimescene(const AActor* Instigator) {
    return false;
}

void UObjectStateInfo::SetupSfx(UAkComponent* AkComponent) {
}

void UObjectStateInfo::SetUnusable(float RestoreUsabilityTime) {
}

void UObjectStateInfo::SetTransformable(bool bTransform) {
}

void UObjectStateInfo::SetTargetable(bool bTargetable) {
}

void UObjectStateInfo::SetSpecialTargetPerceptionActive(bool bActive) {
}

void UObjectStateInfo::SetSizeClass(EObjectSizeClass NewSizeClass) {
}

void UObjectStateInfo::SetShowTargetUI(bool ShowUI) {
}

void UObjectStateInfo::SetSendTargetPriority(uint8 Priority) {
}

void UObjectStateInfo::SetRepairInPlace(bool bInPlace) {
}

void UObjectStateInfo::SetRepairable(bool Repairable) {
}

void UObjectStateInfo::SetProtectedFromDamageAndSpells(bool bInProtected, UObject* InInstigator) {
}

void UObjectStateInfo::SetPersistence(bool InPersistence) {
}

void UObjectStateInfo::SetPercentCharred(float PercentCharred) {
}

void UObjectStateInfo::SetMinOptimumAvatarDistance(float Distance) {
}

void UObjectStateInfo::SetMinDamageThreshold(float Threshold) {
}

void UObjectStateInfo::SetMaxOptimumAvatarDistance(float Distance) {
}

void UObjectStateInfo::SetMaterialSwapped(bool bInMaterialSwapped) {
}

void UObjectStateInfo::SetMarkupValue(EMarkupType MarkupType, float InValue) {
}

bool UObjectStateInfo::SetLocked() {
    return false;
}

void UObjectStateInfo::SetJuggernaut(bool bInJuggernaut) {
}

void UObjectStateInfo::SetIsABoss(bool bInIsABoss) {
}

void UObjectStateInfo::SetInWaterVolume(bool inWater) {
}

void UObjectStateInfo::SetInWater(bool inWater, AActor* Instigator) {
}

void UObjectStateInfo::SetInvulnerableToDamage(bool Invulnerable) {
}

bool UObjectStateInfo::SetInvulnerable(float InInvulnerableTime) {
    return false;
}

void UObjectStateInfo::SetImpulseIgnoreTime(float Time) {
}

void UObjectStateInfo::SetImmuneToSpells(bool bImmune) {
}

void UObjectStateInfo::SetImmuneToEverythingExcept(const FGameplayTagContainer& InImpactTagContainer) {
}

void UObjectStateInfo::SetHighlightWhenBroken(bool bHighlightWhenBroken) {
}

void UObjectStateInfo::SetHidden(bool bHidden) {
}

void UObjectStateInfo::SetHealthBarType(EUIHealthBarType InType) {
}

bool UObjectStateInfo::SetHealth(float Amount, bool bIndicateHUD) {
    return false;
}

void UObjectStateInfo::SetFragile(bool Fragile) {
}

void UObjectStateInfo::SetForceNotBroken(bool bNotBroken) {
}

void UObjectStateInfo::SetForceBroken(bool bBroken) {
}

void UObjectStateInfo::SetFlammable(EFlammableEnum InFlammable) {
}

void UObjectStateInfo::SetExplode(bool bInExplode) {
}

void UObjectStateInfo::SetEquipped(bool bInEquipped) {
}

void UObjectStateInfo::SetDieInWater(bool DieInWater) {
}

void UObjectStateInfo::SetDestructibleMeshByName(const FString& DestuctibleMeshName) {
}

void UObjectStateInfo::SetDestructibleGeometryCollection(UGeometryCollection* DestructibleGeometryCollection) {
}

void UObjectStateInfo::SetDestroyedBaseByName(const FString& BaseName) {
}

void UObjectStateInfo::SetDestroyedBase(UStaticMesh* Base) {
}

void UObjectStateInfo::SetDazed(bool bInDazed) {
}

void UObjectStateInfo::SetDamagable(bool Damagable) {
}

void UObjectStateInfo::SetCurrentlyTargeted(bool CurrentlyTargeted) {
}

void UObjectStateInfo::SetCanHighlight(bool bCanHighlight) {
}

void UObjectStateInfo::SetCanBecomeMovable(bool bCanBecomeMovable) {
}

void UObjectStateInfo::SetBlocking(bool bInBlocking) {
}

void UObjectStateInfo::SetBaseHealth(float Health) {
}

void UObjectStateInfo::RestoreUsability(bool repeat) {
}

void UObjectStateInfo::RestoreMaterial() {
}

void UObjectStateInfo::Reset(bool bOriginalLocation) {
}

bool UObjectStateInfo::RepairChildren() const {
    return false;
}

void UObjectStateInfo::Repair(AActor* RepairInstigator, int32 Item, bool Aoe, bool InOriginalLocation, bool InAutoComplete) {
}

void UObjectStateInfo::RemoveMagicEffects(const TArray<TSubclassOf<UStateEffectComponent>>& EffectTypeList) {
}

void UObjectStateInfo::RemoveMagic() {
}

void UObjectStateInfo::RemoveImmunity(const FGameplayTagContainer& InImpactTagContainer) {
}

void UObjectStateInfo::RemoveImmuneUnlessCritical(const FGameplayTagContainer& InImpactTagContainer) {
}

void UObjectStateInfo::RemoveAllStateEffects() {
}

void UObjectStateInfo::RemoveAllImmunity() {
}

void UObjectStateInfo::RemoveAllImmuneUnlessCritical() {
}

void UObjectStateInfo::RemoveActorMagicEffects(AActor* InActor, const TArray<TSubclassOf<UStateEffectComponent>>& EffectTypeList) {
}

void UObjectStateInfo::OnMunitionImpactDamage(const UObject* i_caller, const FMunitionImpactData& miData) {
}

void UObjectStateInfo::OnCurtainRaised() {
}

void UObjectStateInfo::OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) {
}

void UObjectStateInfo::NotifyCriticalHit() {
}

bool UObjectStateInfo::IsWaterproof() const {
    return false;
}

bool UObjectStateInfo::IsUsableWhenRepaired() const {
    return false;
}

bool UObjectStateInfo::IsUsable() const {
    return false;
}

bool UObjectStateInfo::IsUnusable() const {
    return false;
}

bool UObjectStateInfo::IsTransformable() const {
    return false;
}

bool UObjectStateInfo::IsTargetableWhenBroken() const {
    return false;
}

bool UObjectStateInfo::IsTargetable() const {
    return false;
}

bool UObjectStateInfo::IsSpecialTargetPerceptionActive() const {
    return false;
}

bool UObjectStateInfo::IsSimulatingPhysics() const {
    return false;
}

bool UObjectStateInfo::IsRevelioResource() const {
    return false;
}

bool UObjectStateInfo::IsResurrecting() const {
    return false;
}

bool UObjectStateInfo::IsRepairInPlace() const {
    return false;
}

bool UObjectStateInfo::IsRepairing() const {
    return false;
}

bool UObjectStateInfo::IsRepairable() const {
    return false;
}

bool UObjectStateInfo::IsProtectedFromDeath() {
    return false;
}

bool UObjectStateInfo::IsProtectedFromDamageAndSpells() const {
    return false;
}

bool UObjectStateInfo::IsProtectedCompanion() {
    return false;
}

bool UObjectStateInfo::IsPointOnFire(const FVector& Point, bool LimitToRing) const {
    return false;
}

bool UObjectStateInfo::IsPetrified() const {
    return false;
}

bool UObjectStateInfo::IsPartiallyBroken() const {
    return false;
}

bool UObjectStateInfo::IsOnFire() const {
    return false;
}

bool UObjectStateInfo::IsObstacleDisabled() {
    return false;
}

bool UObjectStateInfo::IsObjectTypeWater() const {
    return false;
}

bool UObjectStateInfo::IsObjectTypePlant() const {
    return false;
}

bool UObjectStateInfo::IsObjectTypeInanimate() const {
    return false;
}

bool UObjectStateInfo::IsObjectTypeAnimate() const {
    return false;
}

bool UObjectStateInfo::IsNoDamageBreakable() const {
    return false;
}

bool UObjectStateInfo::IsNearDeathKneeling() const {
    return false;
}

bool UObjectStateInfo::IsMovable() const {
    return false;
}

bool UObjectStateInfo::IsMounted() const {
    return false;
}

bool UObjectStateInfo::IsMaterialSwapped() const {
    return false;
}

bool UObjectStateInfo::IsLocked() const {
    return false;
}

bool UObjectStateInfo::IsLevitating() const {
    return false;
}

bool UObjectStateInfo::IsInWaterVolume() const {
    return false;
}

bool UObjectStateInfo::IsInWater() const {
    return false;
}

bool UObjectStateInfo::IsInvulnerableToDamage() const {
    return false;
}

bool UObjectStateInfo::IsInvulnerable() const {
    return false;
}

bool UObjectStateInfo::IsInteractive() const {
    return false;
}

bool UObjectStateInfo::IsInNeedOfRepair() const {
    return false;
}

bool UObjectStateInfo::IsImperiousControlled() const {
    return false;
}

bool UObjectStateInfo::IsImmuneToSpells() const {
    return false;
}

bool UObjectStateInfo::IsImmuneToFireDamage() const {
    return false;
}

bool UObjectStateInfo::IsHidden() const {
    return false;
}

bool UObjectStateInfo::IsHealthZero() const {
    return false;
}

bool UObjectStateInfo::IsHealthCritical(bool bIgnorePendingDamage) {
    return false;
}

bool UObjectStateInfo::IsFrozen() const {
    return false;
}

bool UObjectStateInfo::IsFreezable() const {
    return false;
}

bool UObjectStateInfo::IsFragile() const {
    return false;
}

bool UObjectStateInfo::IsFlammable() const {
    return false;
}

bool UObjectStateInfo::IsFightClubOpponent() {
    return false;
}

bool UObjectStateInfo::IsFallDamageDisabled() {
    return false;
}

bool UObjectStateInfo::IsEquipped() const {
    return false;
}

bool UObjectStateInfo::IsDisillusioned() const {
    return false;
}

bool UObjectStateInfo::IsDead() const {
    return false;
}

bool UObjectStateInfo::IsDazed() const {
    return false;
}

bool UObjectStateInfo::IsDamagableWhenFrozen() const {
    return false;
}

bool UObjectStateInfo::IsDamagableWhenCharred() const {
    return false;
}

bool UObjectStateInfo::IsDamagableInPieces() const {
    return false;
}

bool UObjectStateInfo::IsDamagable() const {
    return false;
}

bool UObjectStateInfo::IsCuttable() const {
    return false;
}

bool UObjectStateInfo::IsCursed() const {
    return false;
}

bool UObjectStateInfo::IsCrucioed() const {
    return false;
}

bool UObjectStateInfo::IsCommonBreakable() const {
    return false;
}

bool UObjectStateInfo::IsCombatCursed() const {
    return false;
}

bool UObjectStateInfo::IsCharred() const {
    return false;
}

bool UObjectStateInfo::IsCharacterOnGroundWithHitResult(const AActor* InActor, FHitResult& OutHitResult) {
    return false;
}

bool UObjectStateInfo::IsCharacterOnGround(const AActor* InActor) {
    return false;
}

bool UObjectStateInfo::IsBurning() const {
    return false;
}

bool UObjectStateInfo::IsBrokenOrPartiallyBroken() const {
    return false;
}

bool UObjectStateInfo::IsBroken() const {
    return false;
}

bool UObjectStateInfo::IsBlocking() const {
    return false;
}

bool UObjectStateInfo::IsBeingAffectedBySpells() {
    return false;
}

bool UObjectStateInfo::IsAWolf() const {
    return false;
}

bool UObjectStateInfo::IsAWizard() const {
    return false;
}

bool UObjectStateInfo::IsAwake() {
    return false;
}

bool UObjectStateInfo::IsATroll() const {
    return false;
}

bool UObjectStateInfo::IsATransformedCharacter() const {
    return false;
}

bool UObjectStateInfo::IsAStudent() const {
    return false;
}

bool UObjectStateInfo::IsAStation() const {
    return false;
}

bool UObjectStateInfo::IsASpider() const {
    return false;
}

bool UObjectStateInfo::IsArrestoMomentumed() const {
    return false;
}

bool UObjectStateInfo::IsARagdoll() const {
    return false;
}

bool UObjectStateInfo::IsAProtectedCharacterWhichCannotDie() const {
    return false;
}

bool UObjectStateInfo::IsAProfessor() const {
    return false;
}

bool UObjectStateInfo::IsAPortraitCharacter() const {
    return false;
}

bool UObjectStateInfo::IsAPlayer() const {
    return false;
}

bool UObjectStateInfo::IsAPlant() const {
    return false;
}

bool UObjectStateInfo::IsAnOppugnoTarget() const {
    return false;
}

bool UObjectStateInfo::IsAnInferi() const {
    return false;
}

bool UObjectStateInfo::IsAnEnvironment() const {
    return false;
}

bool UObjectStateInfo::IsAnEnemy() const {
    return false;
}

bool UObjectStateInfo::IsANamedCharacter() const {
    return false;
}

bool UObjectStateInfo::IsAMount() const {
    return false;
}

bool UObjectStateInfo::IsAMagicalCreatureWhichCannotDie() const {
    return false;
}

bool UObjectStateInfo::IsAlly(const AActor* ActorPtr) const {
    return false;
}

bool UObjectStateInfo::IsALeader() const {
    return false;
}

bool UObjectStateInfo::IsAJuggernaut() const {
    return false;
}

bool UObjectStateInfo::IsAHouseElf() const {
    return false;
}

bool UObjectStateInfo::IsAHobo() const {
    return false;
}

bool UObjectStateInfo::IsAGoblin() const {
    return false;
}

bool UObjectStateInfo::IsAGhost() const {
    return false;
}

bool UObjectStateInfo::IsADugbog() const {
    return false;
}

bool UObjectStateInfo::IsADragon() const {
    return false;
}

bool UObjectStateInfo::IsADarkWizard() const {
    return false;
}

bool UObjectStateInfo::IsActorSimulatingPhysics(const AActor* InActor) {
    return false;
}

bool UObjectStateInfo::IsActorLeviosoActive(const AActor* InActor) {
    return false;
}

bool UObjectStateInfo::IsACreature() const {
    return false;
}

bool UObjectStateInfo::IsACompanion() const {
    return false;
}

bool UObjectStateInfo::IsACharacter() const {
    return false;
}

bool UObjectStateInfo::IsACentaur() const {
    return false;
}

bool UObjectStateInfo::IsABossCharacter() const {
    return false;
}

bool UObjectStateInfo::IsABiped() const {
    return false;
}

bool UObjectStateInfo::IgnoreMunitionImpactEvents() const {
    return false;
}

bool UObjectStateInfo::IgnoreLimitedCountRules() const {
    return false;
}

bool UObjectStateInfo::IgnoreActorHitEvents() const {
    return false;
}

bool UObjectStateInfo::HasStateEffect() const {
    return false;
}

bool UObjectStateInfo::HasOnFireDoT() const {
    return false;
}

bool UObjectStateInfo::HasBecomeMovable() const {
    return false;
}

bool UObjectStateInfo::HasAffectingSpells() {
    return false;
}

float UObjectStateInfo::GetWetness() const {
    return 0.0f;
}

UVelocityTrackerComponent* UObjectStateInfo::GetVelocityTracker() const {
    return NULL;
}

float UObjectStateInfo::GetUIHealthPercent() const {
    return 0.0f;
}

FName UObjectStateInfo::GetType() const {
    return NAME_None;
}

float UObjectStateInfo::GetTodaysPlayerGainedSoCapCount() {
    return 0.0f;
}

float UObjectStateInfo::GetStudentsInInfirmary() {
    return 0.0f;
}

bool UObjectStateInfo::GetStartAsleep() const {
    return false;
}

float UObjectStateInfo::GetSizeClassOnFireDestroyedDamage() const {
    return 0.0f;
}

TSubclassOf<AMunitionType_Base> UObjectStateInfo::GetSizeClassOnFireDestroyedAOE() const {
    return NULL;
}

float UObjectStateInfo::GetSizeClassFireDamageMultiplier() const {
    return 0.0f;
}

EObjectSizeClass UObjectStateInfo::GetSizeClass() const {
    return EObjectSizeClass::XXS;
}

bool UObjectStateInfo::GetShowTargetUI() {
    return false;
}

uint8 UObjectStateInfo::GetSendTargetPriority() const {
    return 0;
}

float UObjectStateInfo::GetRawCurrentHealth() const {
    return 0.0f;
}

bool UObjectStateInfo::GetRagdollInfo(FVector& Location, FVector& Velocity) {
    return false;
}

FName UObjectStateInfo::GetRagdollBoneName() const {
    return NAME_None;
}

float UObjectStateInfo::GetPlayerPottedPlants() {
    return 0.0f;
}

float UObjectStateInfo::GetPlayerFriendsCount() {
    return 0.0f;
}

float UObjectStateInfo::GetPlayerEnemiesCount() {
    return 0.0f;
}

float UObjectStateInfo::GetPlayerConsecutiveEnemyHits() {
    return 0.0f;
}

float UObjectStateInfo::GetPlayerCompletedFactSheets() {
    return 0.0f;
}

bool UObjectStateInfo::GetPersistence() {
    return false;
}

float UObjectStateInfo::GetPercentCharred() const {
    return 0.0f;
}

UObjectStateInfoData* UObjectStateInfo::GetObjectStateInfoData() {
    return NULL;
}

ENoiseSize UObjectStateInfo::GetObjectNoiseSize() const {
    return ENoiseSize::NoNoise;
}

float UObjectStateInfo::GetNormalHarvestCount() {
    return 0.0f;
}

void UObjectStateInfo::GetNonScaledActorBounds(const AActor* InActor, bool bOnlyCollidingComponents, FVector& Origin, FVector& BoxExtent) {
}

bool UObjectStateInfo::GetNeverAffectNavmesh() const {
    return false;
}

bool UObjectStateInfo::GetNavOverrideMobilityCheck() const {
    return false;
}

float UObjectStateInfo::GetMinOptimumAvatarDistance() const {
    return 0.0f;
}

float UObjectStateInfo::GetMinDamageThreshold() const {
    return 0.0f;
}

float UObjectStateInfo::GetMaxOptimumAvatarDistance() const {
    return 0.0f;
}

float UObjectStateInfo::GetMaxHealth() const {
    return 0.0f;
}

UMaterialPropertyData* UObjectStateInfo::GetMaterialPropertyData() const {
    return NULL;
}

float UObjectStateInfo::GetMass() const {
    return 0.0f;
}

bool UObjectStateInfo::GetMarkupValue(EMarkupType MarkupType, float& OutValue) const {
    return false;
}

float UObjectStateInfo::GetLockValue() const {
    return 0.0f;
}

float UObjectStateInfo::GetLevel() const {
    return 0.0f;
}

bool UObjectStateInfo::GetLastDamageInReactionAdjustment() const {
    return false;
}

bool UObjectStateInfo::GetKilledWithAvadaKedavra() const {
    return false;
}

EImpactTypes UObjectStateInfo::GetImpactType() const {
    return EImpactTypes::None;
}

UAkAudioEvent* UObjectStateInfo::GetHitSfx() const {
    return NULL;
}

float UObjectStateInfo::GetHealthPercentage() const {
    return 0.0f;
}

EUIHealthBarType UObjectStateInfo::GetHealthBarType() {
    return EUIHealthBarType::HBT_Normal;
}

float UObjectStateInfo::GetHealth() const {
    return 0.0f;
}

float UObjectStateInfo::GetFrozenDamageMultiplier() const {
    return 0.0f;
}

float UObjectStateInfo::GetFireDamagePerSecond() const {
    return 0.0f;
}

float UObjectStateInfo::GetFireDamageFloor() const {
    return 0.0f;
}

UAkAudioEvent* UObjectStateInfo::GetFastSfx() const {
    return NULL;
}

bool UObjectStateInfo::GetDisplayDamage() const {
    return false;
}

UStaticMesh* UObjectStateInfo::GetDestroyedBase() const {
    return NULL;
}

FName UObjectStateInfo::GetDbVoiceId() const {
    return NAME_None;
}

FName UObjectStateInfo::GetDbTypeId() const {
    return NAME_None;
}

FName UObjectStateInfo::GetDbSubtypeID() const {
    return NAME_None;
}

FName UObjectStateInfo::GetDbPersistentId() const {
    return NAME_None;
}

FName UObjectStateInfo::GetDbLookId() const {
    return NAME_None;
}

FName UObjectStateInfo::GetDbId() const {
    return NAME_None;
}

FName UObjectStateInfo::GetDbGenderId() const {
    return NAME_None;
}

FName UObjectStateInfo::GetDbEmoteVoiceId() const {
    return NAME_None;
}

FName UObjectStateInfo::GetDbClassId() const {
    return NAME_None;
}

float UObjectStateInfo::GetCursedEnemyCount() {
    return 0.0f;
}

bool UObjectStateInfo::GetCurrentlyTargeted() {
    return false;
}

float UObjectStateInfo::GetCurrentItemEffectiveness() {
    return 0.0f;
}

UPhoenixPhysicalMaterial* UObjectStateInfo::GetComponentPhoenixPhysicalMaterial(const UPrimitiveComponent* InPrimComponent) {
    return NULL;
}

float UObjectStateInfo::GetCompanionLevel() const {
    return 0.0f;
}

float UObjectStateInfo::GetCharredDamageMultiplier() const {
    return 0.0f;
}

FVector UObjectStateInfo::GetBrokenPieceLocation() const {
    return FVector{};
}

EBossStates UObjectStateInfo::GetBossState() const {
    return EBossStates::BS_None;
}

float UObjectStateInfo::GetBaseHealth() const {
    return 0.0f;
}

float UObjectStateInfo::GetActorMass(const AActor* InActor) {
    return 0.0f;
}

UPrimitiveComponent* UObjectStateInfo::GetActorMainPrimitiveComponent(const AActor* InActor) {
    return NULL;
}

EImpactTypes UObjectStateInfo::GetActorImpactType(const AActor* InActor) {
    return EImpactTypes::None;
}

AActor* UObjectStateInfo::GetActor() const {
    return NULL;
}

void UObjectStateInfo::ForceBreak(float InScale, bool InRestoreBroken) {
}

void UObjectStateInfo::ForceAsleep() {
}

void UObjectStateInfo::ExtendNearDeathKneel(float KneelTime) {
}

bool UObjectStateInfo::EndAffectingSpells() {
    return false;
}

AActor* UObjectStateInfo::DropLootContainer(FVector InLocation) {
    return NULL;
}

AActor* UObjectStateInfo::DropCooldownPickup(FVector InLocation) {
    return NULL;
}

bool UObjectStateInfo::DoHealing(float Amount, AActor* InInstigator, UPrimitiveComponent* PrimComp, int32 Item, bool bAoe, bool InOriginalLocation, bool InAutoComplete) {
    return false;
}

bool UObjectStateInfo::DoFireDamage(float Amount, AActor* Instigator) {
    return false;
}

bool UObjectStateInfo::DoesExplode() const {
    return false;
}

void UObjectStateInfo::DisableObjectState(bool bInDisabled) {
}

void UObjectStateInfo::DisableFallDamage(bool bDisable) {
}

void UObjectStateInfo::DisableDamageMods(bool bDisable) {
}

bool UObjectStateInfo::DiesInWater() const {
    return false;
}

void UObjectStateInfo::DelayedRestoreUsability(float Delay) {
}

void UObjectStateInfo::DelayedRestoreBroken(float InTime) {
}

void UObjectStateInfo::DelayedForceBreak(float InTime) {
}

bool UObjectStateInfo::DecreaseWetness(float Amount) {
    return false;
}

bool UObjectStateInfo::DecreaseFire(float Amount) {
    return false;
}

void UObjectStateInfo::Deactivate() {
}

void UObjectStateInfo::DamageInPieces(float InImpulseStr, float InDamage, const FVector& InHitLocation, const FVector& InHitDirection, float InRadius) {
}

void UObjectStateInfo::CreateNoise(ENoiseSize NoiseSize, const FVector& NoiseLocation, AActor* NoiseInstigator, FGameplayTagContainer EventContainer) const {
}

void UObjectStateInfo::ClearInvulnerable() {
}

void UObjectStateInfo::ClearImmuneToEverythingExcept() {
}

void UObjectStateInfo::ClearCurrentVelocity() {
}

void UObjectStateInfo::ClearCooldownPickupTargets() {
}

void UObjectStateInfo::CheckObstacleSetup() {
}

bool UObjectStateInfo::CanHighlightWhenBroken() const {
    return false;
}

bool UObjectStateInfo::CanHighlight() const {
    return false;
}

bool UObjectStateInfo::CanBeRepaired() const {
    return false;
}

bool UObjectStateInfo::CanBecomeMovable() const {
    return false;
}

void UObjectStateInfo::BreakStaticDestructibleMesh(float InImpulseStr, const FVector& InHitLocation, const FVector& InHitDirection, UParticleSystem* InDestroyEffects, float InEffectRadius, float InRadius, float AdditionalDestructionForce, float AngularForceMultiplier) {
}

void UObjectStateInfo::BecomeMovable(bool bBecomeMovable) {
}

bool UObjectStateInfo::AdjustHealth(float change, bool bIndicateHUD) {
    return false;
}

void UObjectStateInfo::AddImmunity(const FGameplayTagContainer& InImpactTagContainer) {
}

void UObjectStateInfo::AddImmuneUnlessCritical(const FGameplayTagContainer& InImpactTagContainer) {
}

void UObjectStateInfo::AddCooldownPickupTarget(const FVector& InTarget) {
}

void UObjectStateInfo::ActorStopSimulatingPhysics(AActor* InActor) {
}

void UObjectStateInfo::ActorStartSimulatingPhysics(AActor* InActor) {
}

void UObjectStateInfo::ActorHitShake(float Damage, const FVector& ImpactLocation) {
}

void UObjectStateInfo::Activate() {
}

UObjectStateInfo::UObjectStateInfo() {
    this->WidgetType = EWidgetType::WT_Social;
    this->MaterialPropertyData = NULL;
    this->Actor = NULL;
    this->ObjectStateData = NULL;
    this->OdcObstacleComponent = NULL;
    this->RepairInfo = NULL;
    this->DynamicNavigationAreaObstacleComponent = NULL;
}

