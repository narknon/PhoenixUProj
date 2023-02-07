#include "NPC_ReactionComponent.h"

class UAblReactionComponent;
class UAblReactionData;
class UObject;

void UNPC_ReactionComponent::StartSettingReactionsEnabledValue(bool bValue, ECharacterShutdownPriority Priority, UObject* InInstigator) {
}

void UNPC_ReactionComponent::StartSettingReactionsEnabledFromAlliesValue(bool bValue, EStandardManagedPriority Priority, UObject* InInstigator) {
}

bool UNPC_ReactionComponent::IsFullBodyReactionQueuedOrRunning(UAblReactionComponent* ReactionComponent) {
    return false;
}

void UNPC_ReactionComponent::HandleReactionFinished(UAblReactionData* ReactionData, UAblReactionComponent* ReactionComponent) {
}

void UNPC_ReactionComponent::FinishSettingReactionsEnabledValue(ECharacterShutdownPriority Priority, UObject* InInstigator) {
}

void UNPC_ReactionComponent::FinishSettingReactionsEnabledFromAlliesValue(UObject* InInstigator) {
}

UNPC_ReactionComponent::UNPC_ReactionComponent() {
    this->Config = NULL;
}

