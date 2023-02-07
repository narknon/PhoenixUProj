#include "TriggerEffectComponent.h"

void UTriggerEffectComponent::RemoveObjectTypeToAffect(TEnumAsByte<EObjectTypeQuery> ObjectType) {
}

void UTriggerEffectComponent::AddObjectTypeToAffect(TEnumAsByte<EObjectTypeQuery> ObjectType) {
}

UTriggerEffectComponent::UTriggerEffectComponent() {
    this->TriggerForEffect = EInteractiveAction::None;
    this->SpellToBeUsed = NULL;
    this->TimeBeforeTriggerStarts = 0.50f;
    this->bUseSpellImpactFX = false;
    this->bUseSpellMuzzleFX = false;
    this->TriggerEffectVfx = NULL;
    this->TriggerEffectSfx = NULL;
    this->bAffectsSpecificActors = false;
    this->bUseRadiusForEffect = false;
    this->Radius = 200.00f;
    this->bIgnoreOwningActor = false;
    this->ParticleSystemComponent = NULL;
}

