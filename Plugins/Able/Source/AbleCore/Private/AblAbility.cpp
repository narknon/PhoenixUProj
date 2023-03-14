#include "AblAbility.h"

class AActor;
class UAblAbility;
class UAblAbilityContext;

bool UAblAbility::RequiresTarget() const {
    return false;
}

bool UAblAbility::RequiresAllTasksComplete() const {
    return false;
}

bool UAblAbility::RefreshLoopTimeOnly() const {
    return false;
}

bool UAblAbility::RefreshDurationOnNewStack() const {
    return false;
}



UAblAbility* UAblAbility::OnGetBranchAbility_Implementation(const UAblAbilityContext* Context, const FName& EventName) const {
    return NULL;
}







bool UAblAbility::MustPassAllChannelConditions() const {
    return false;
}

bool UAblAbility::IsPassive() const {
    return false;
}

bool UAblAbility::IsLooping() const {
    return false;
}

bool UAblAbility::IsChanneled() const {
    return false;
}

float UAblAbility::GetRange() const {
    return 0.0f;
}

int32 UAblAbility::GetMaxStacks_Implementation(const UAblAbilityContext* Context) const {
    return 0;
}

FVector2D UAblAbility::GetLoopRange() const {
    return FVector2D{};
}

int32 UAblAbility::GetLoopMaxIterationsBP() const {
    return 0;
}

float UAblAbility::GetLength() const {
    return 0.0f;
}

FString UAblAbility::GetDisplayName() const {
    return TEXT("");
}

float UAblAbility::GetCooldown() const {
    return 0.0f;
}

float UAblAbility::GetBasePlayRate() const {
    return 0.0f;
}

int32 UAblAbility::GetBaseMaxStacks() const {
    return 0;
}

float UAblAbility::GetBaseCooldown() const {
    return 0.0f;
}

FGameplayTagContainer UAblAbility::GetAbilityTagContainer() const {
    return FGameplayTagContainer{};
}


bool UAblAbility::CustomFilterCondition_Implementation(const UAblAbilityContext* Context, const FName& EventName, AActor* Actor) const {
    return false;
}

bool UAblAbility::CustomCanLoopExecute_Implementation(const UAblAbilityContext* Context) const {
    return false;
}

bool UAblAbility::CustomCanBranchTo_Implementation(const UAblAbilityContext* Context) const {
    return false;
}

bool UAblAbility::CustomCanAbilityExecute_Implementation(const UAblAbilityContext* Context) const {
    return false;
}

bool UAblAbility::CheckCustomChannelConditional_Implementation(const UAblAbilityContext* Context, const FName& EventName) const {
    return false;
}

bool UAblAbility::CanInterruptAbility_Implementation(const UAblAbilityContext* Context, const UAblAbility* CurrentAbility) const {
    return false;
}

float UAblAbility::CalculateDamageForActor_Implementation(const UAblAbilityContext* Context, const FName& EventName, float BaseDamage, AActor* Actor) const {
    return 0.0f;
}

float UAblAbility::CalculateCooldown_Implementation(const UAblAbilityContext* Context) const {
    return 0.0f;
}

bool UAblAbility::AlwaysRefreshDuration() const {
    return false;
}



UAblAbility::UAblAbility() {
    this->m_Length = 1.00f;
    this->m_Cooldown = 0.00f;
    this->m_PlayRate = 1.00f;
    this->m_bOverrideGlobalPlayRate = false;
    this->m_IsPassive = false;
    this->m_MaxStacks = 1;
    this->m_RefreshDurationOnNewStack = true;
    this->m_AlwaysRefreshDuration = false;
    this->m_OnlyRefreshLoopTime = false;
    this->m_RequiresAllTasksComplete = false;
    this->m_Loop = false;
    this->m_LoopStart = 0.00f;
    this->m_LoopEnd = 1.00f;
    this->m_LoopMaxIterations = 0;
    this->m_RequiresTarget = false;
    this->m_Targeting = NULL;
    this->m_IsChanneled = false;
    this->m_MustPassAllChannelConditions = false;
    this->m_AbilityNameHash = 0;
    this->m_AbilityRealm = EAblAbilityTaskRealm::Client;
}


void UAblAbility::PostLoad()
{
    Super::PostLoad();
	// Generate our Name hash.
	m_AbilityNameHash = FCrc::StrCrc32(*GetName());
}

