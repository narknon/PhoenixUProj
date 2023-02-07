#include "AblAbilityContext.h"

class AActor;
class UAblAbilityComponent;

void UAblAbilityContext::SetStackCount(int32 Stack) {
}

TArray<AActor*> UAblAbilityContext::GetTargetActors() const {
    return TArray<AActor*>();
}

AActor* UAblAbilityContext::GetSelfActor() const {
    return NULL;
}

UAblAbilityComponent* UAblAbilityContext::GetSelfAbilityComponent() const {
    return NULL;
}

AActor* UAblAbilityContext::GetOwner() const {
    return NULL;
}

AActor* UAblAbilityContext::GetInstigator() const {
    return NULL;
}

float UAblAbilityContext::GetCurrentTimeRatio() const {
    return 0.0f;
}

float UAblAbilityContext::GetCurrentTime() const {
    return 0.0f;
}

int32 UAblAbilityContext::GetCurrentStackCount() const {
    return 0;
}

UAblAbilityContext::UAblAbilityContext() {
    this->m_Ability = NULL;
    this->m_AbilityComponent = NULL;
    this->m_StackCount = 1;
    this->m_CurrentTime = 0.00f;
    this->AbilityScratchPad = NULL;
    this->m_UseSourceRootMotion = EEvaluatorRootMotion::ERM_StandardNoRotation;
    this->m_UseDestRootMotion = EEvaluatorRootMotion::ERM_StandardFullRotation;
    this->m_BlendTickStyle = EAnimBlendTickStyle::BlendTickBoth;
}

