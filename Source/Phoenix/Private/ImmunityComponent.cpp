#include "ImmunityComponent.h"

void UImmunityComponent::SetImmuneToEverythingExcept(const FGameplayTagContainer& InImpactTagContainer) {
}

void UImmunityComponent::RemoveImmunity(const FGameplayTagContainer& InImpactTagContainer) {
}

void UImmunityComponent::RemoveImmuneUnlessCritical(const FGameplayTagContainer& InImpactTagContainer) {
}

void UImmunityComponent::RemoveAllImmunity() {
}

void UImmunityComponent::RemoveAllImmuneUnlessCritical() {
}

bool UImmunityComponent::IsImmuneTo(const FGameplayTagContainer& InImpactTagContainer, bool bCritical) const {
    return false;
}

void UImmunityComponent::ClearImmuneToEverythingExcept() {
}

void UImmunityComponent::AddImmunity(const FGameplayTagContainer& InImpactTagContainer) {
}

void UImmunityComponent::AddImmuneUnlessCritical(const FGameplayTagContainer& InImpactTagContainer) {
}

UImmunityComponent::UImmunityComponent() {
    this->bImmuneToEverythingExcept = false;
}

