#include "AblReactionComponent.h"
#include "Templates/SubclassOf.h"

class UAblAbilityContext;
class UAblReactionAbility;
class UAblReactionData;

UAblReactionData* UAblReactionComponent::QueueReaction(const FQueueReactionParams& ReactionParams) {
    return NULL;
}

UAblReactionData* UAblReactionComponent::QueueGivenReactionAbility(TSubclassOf<UAblReactionAbility> ReactionAbility, const FQueueReactionParams& ReactionParams) {
    return NULL;
}

UAblReactionData* UAblReactionComponent::QueueGivenReactionAbilities(TArray<TSubclassOf<UAblReactionAbility>> ReactionAbilities, const FQueueReactionParams& ReactionParams) {
    return NULL;
}

FQueueReactionParams UAblReactionComponent::MakeReactionParamsFromReactionData(const UAblReactionData* ReactionData) {
    return FQueueReactionParams{};
}

bool UAblReactionComponent::IsAnyReactionRunning() const {
    return false;
}

void UAblReactionComponent::HandleReactionAbilityStart(const UAblAbilityContext* Context) {
}

void UAblReactionComponent::HandleReactionAbilityInterrupt(const UAblAbilityContext* Context) {
}

void UAblReactionComponent::HandleReactionAbilityEnd(const UAblAbilityContext* Context) {
}

void UAblReactionComponent::HandleReactionAbilityBranch(const UAblAbilityContext* CurrentContext, const UAblAbilityContext* NextContext) {
}

void UAblReactionComponent::EnableReactions() {
}

void UAblReactionComponent::DisableReactions() {
}

UAblReactionComponent::UAblReactionComponent() {
    this->AbleAbilityComp = NULL;
    this->AnimationArchitectComp = NULL;
}

