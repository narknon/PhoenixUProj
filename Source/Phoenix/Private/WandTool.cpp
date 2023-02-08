#include "WandTool.h"
#include "ToolSetComponent.h"
#include "TriggerEffect.h"
#include "Templates/SubclassOf.h"

class AActor;
class AFlyingBook;
class AProtegoSpellTool;
class ASpellTool;
class ATool;
class UAblAbility;
class UReticule;
class USpellToolRecord;

void AWandTool::WandCastFailedTimerExpired() {
}

void AWandTool::TurnOnTriggerEffects() {
}

void AWandTool::TurnOffTriggerEffects() {
}

void AWandTool::TargetSpellSelected(bool Immediate) {
}

bool AWandTool::StopLastSpell(ASpellTool* NewSpellTool, bool& OutAlreadyActivated) {
    return false;
}



void AWandTool::SpellPreload() {
}


void AWandTool::SetProjectileSpeedMultiplier(float Multiplier) {
}

void AWandTool::SetNextWandCastType(EWandCastType::Type WandCastState) {
}

void AWandTool::SetNextLightCastAbility(TSubclassOf<UAblAbility> InAbility) {
}

void AWandTool::SetNextHeavyCastAbility(TSubclassOf<UAblAbility> InAbility) {
}

void AWandTool::SetFinishersActive(bool bActive) {
}

void AWandTool::SetContextsOnBarSpell(int32 Index, bool bFlag) {
}

void AWandTool::SetAttackingActor(AActor* i_attackingActor) {
}

void AWandTool::SetAimTransform(FVector Target) {
}




void AWandTool::ResetComboOnBranch() {
}

void AWandTool::RemoveCollectibleBook(AFlyingBook* book) {
}

void AWandTool::OnSpellLoaded(USpellToolRecord* SpellToolRecord) {
}

void AWandTool::OnSpellCasted() {
}

void AWandTool::OnSpell_Released(const int32 SpellSlot) {
}

void AWandTool::OnSpell_Pressed(const int32 SpellSlot) {
}

void AWandTool::OnRightArmStateChanged(ERightArmState::Type RightArmState, ERightArmState::Type LastRightArmState) {
}

void AWandTool::OnCharacterLoadComplete(AActor* Actor) {
}

void AWandTool::OnActiveSpellToolChanged(ATool* ActivatedSpell, ATool* DeactivatedSpell) {
}

bool AWandTool::LoadSpellByName(AActor* InActor, const FString& Spell, bool Async, bool HighPriority) {
    return false;
}

bool AWandTool::LoadAllSlottedSpells(AActor* InActor) {
    return false;
}

bool AWandTool::LoadAllAccessibleSpells(AActor* InActor) {
    return false;
}

bool AWandTool::IsSpellToolAvailable(USpellToolRecord* SpellToolRecord, bool bImmediate) {
    return false;
}


int32 AWandTool::GetTargetSpellIndex() {
    return 0;
}

ASpellTool* AWandTool::GetSpellTool(USpellToolRecord* SpellToolRecord) const {
    return NULL;
}

USpellToolRecord* AWandTool::GetSpellRecordFromSlot(int32 Index) {
    return NULL;
}

UReticule* AWandTool::GetReticleWidget() {
    return NULL;
}

AProtegoSpellTool* AWandTool::GetProtegoSpellTool() {
    return NULL;
}

float AWandTool::GetProjectileSpeedMultiplier() const {
    return 0.0f;
}

ASpellTool* AWandTool::GetFinisherSpellTool(const int32 SpellSlot) {
    return NULL;
}

ASpellTool* AWandTool::GetActiveSpellTool() const {
    return NULL;
}

void AWandTool::EndSpellCast(ASpellTool*& InSpellTool) {
}

void AWandTool::ComputeParryAimTransform() {
}

bool AWandTool::CheckRequiredPerks(const FGameplayTagContainer& PerkContainer) {
    return false;
}

bool AWandTool::CastStealthTakedown() {
    return false;
}

bool AWandTool::CastSpell(ASpellTool* InSpellTool, bool bImmediate) {
    return false;
}

bool AWandTool::CastPewPewSpell() {
    return false;
}

bool AWandTool::CastActiveSpell() {
    return false;
}


void AWandTool::CancelCurrentSpell() {
}


bool AWandTool::BlockStart() {
    return false;
}

void AWandTool::BlockEnd() {
}

void AWandTool::BarItemSelected(AActor* InActor, int32 Index, bool bFlag) {
}

bool AWandTool::AreFinishersActive() const {
    return false;
}

bool AWandTool::AreAllSlottedSpellsLoaded(AActor* InActor) {
    return false;
}

bool AWandTool::AreAllAccessibleSpellsLoaded(AActor* InActor) {
    return false;
}

void AWandTool::ApplyTriggerEffectDefault(bool RightTrigger, bool LeftTrigger) {
}

void AWandTool::AddCollectibleBook(AFlyingBook* book) {
}

ASpellTool* AWandTool::ActivateSpellTool(USpellToolRecord* SpellToolRecord, bool bImmediate) {
    return NULL;
}

bool AWandTool::ActivateInstantSpellTool(int32 Index) {
    return false;
}

AWandTool::AWandTool() {
    this->SpellButtonWatcher = NULL;
    this->EquipExecutionClass = NULL;
    this->UnequipExecutionClass = NULL;
    this->HoldExecutionClass = NULL;
    this->HandOnlyAbleExecutionClass = NULL;
    this->SpecialAbleExecutionClass = NULL;
    this->TargetSightedExecutionClass = NULL;
    this->AlertedExecutionClass = NULL;
    this->HeavyAnticipationExecutionClass = NULL;
    this->StartLumosExecutionClass = NULL;
    this->ChannelingExecutionClass = NULL;
    this->WandCastFailExecutionClass = NULL;
    this->WandCastFailMoveExecutionClass = NULL;
    this->NextLightCastAbility = NULL;
    this->NextHeavyCastAbility = NULL;
    this->StartingCasualLightCastAbility = NULL;
    this->StartingCombatLightCastAbility = NULL;
    this->m_chargeTime = 0.00f;
    this->m_fireRate = 0.00f;
    this->m_failDueToCooldown = NULL;
    this->m_failDueToCooldownVFX = NULL;
    this->bFinishersActive = false;
    this->MeleeRange = 0.00f;
    this->MeleeHalfAngle = 45.00f;
    this->SpellBlock = NULL;
    this->SpellBlockDH = NULL;
    this->SpellPewPew = NULL;
    this->SpellPewPewDH = NULL;
    this->StealthAttack = NULL;
    this->AvailableSpellLoadoutIndex = 0;
    this->ProtegoRetaliateSpell = NULL;
    this->RightTriggerDefaultEffect = UTriggerEffect::StaticClass();
    this->LeftTriggerDefaultEffect = UTriggerEffect::StaticClass();
    this->pRightTriggerDefaultEffect = NULL;
    this->pLeftTriggerDefaultEffect = NULL;
    this->ToolSetComponent = CreateDefaultSubobject<UToolSetComponent>(TEXT("Spell Tools"));
}

