#include "Base_Character.h"
#include "PhoenixManagedCharacter.h"

class ASocialReasoning;
class UCharacterStateInfo;
class UObject;
class UObjectStateInfo;

void ABase_Character::StartSettingTargetableByAiState(bool bTargetable, EStandardManagedPriority Priority, const UObject* Provider) {
}

void ABase_Character::StartSettingMaxHeightValue(float bValue, EStandardManagedPriority Priority, UObject* InInstigator) {
}

void ABase_Character::StartSettingMaxHeightEnabledValue(bool bValue, EStandardManagedPriority Priority, UObject* InInstigator) {
}

void ABase_Character::StartSettingLODOverride(int32 LODOverride, UObject* Provider) {
}

void ABase_Character::RunEQS_FindStations_Implementation(EEnvQueryRunMode::Type RunMode, FQueryFinishedData& QueryFinishedDelegate) {
}

void ABase_Character::RunEQS_FindSocialReasonings_Implementation(EEnvQueryRunMode::Type RunMode, FQueryFinishedData& QueryFinishedDelegate) {
}

void ABase_Character::ReRegisterWithSignificanceManager() {
}

void ABase_Character::ReleaseFocusFromScriptedBehavior(FName InIdentifyingName) {
}

void ABase_Character::PlayerSighted_Implementation() {
}

bool ABase_Character::Nevermind_Implementation() {
    return false;
}

bool ABase_Character::IsTargetableByAi() const {
    return false;
}

bool ABase_Character::Goodbye_Implementation() {
    return false;
}

ASocialReasoning* ABase_Character::GetSocialReasoning() {
    return NULL;
}

UObjectStateInfo* ABase_Character::GetObjectStateInfo() const {
    return NULL;
}

UCharacterStateInfo* ABase_Character::GetCharacterStateInfo() const {
    return NULL;
}

void ABase_Character::FinishSettingTargetableByAiState(EStandardManagedPriority Priority, const UObject* Provider) {
}

void ABase_Character::FinishSettingMaxHeightValue(EStandardManagedPriority Priority, UObject* InInstigator) {
}

void ABase_Character::FinishSettingMaxHeightEnabledValue(EStandardManagedPriority Priority, UObject* InInstigator) {
}

void ABase_Character::FinishSettingLODOverride(UObject* Provider) {
}

void ABase_Character::ExcuseMe_Implementation() {
}

void ABase_Character::DisableCcd() {
}

void ABase_Character::ConverseWithProxy_Implementation(FSocialResponse& SocialResponse) {
}

void ABase_Character::Converse_Implementation(FSocialResponse& SocialResponse) {
}

void ABase_Character::Chat_Implementation() {
}

void ABase_Character::CaptureFocusForScriptedBehavior(FName InIdentifyingName) {
}

ABase_Character::ABase_Character() {
    this->ManagedCharacter = CreateDefaultSubobject<UPhoenixManagedCharacter>(TEXT("ManagedCharacter"));
    this->TraversalSettings = NULL;
    this->ShoulderFixupAlpha = 0.00f;
    this->FadeOutAlphaFactor = 1.00f;
    this->CachedCharacterStateInfo = NULL;
    this->ClothSitComponent = NULL;
    this->DefaultMaxHeight = 200.00f;
}

