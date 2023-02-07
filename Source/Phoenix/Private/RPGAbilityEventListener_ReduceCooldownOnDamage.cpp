#include "RPGAbilityEventListener_ReduceCooldownOnDamage.h"

class AActor;

void URPGAbilityEventListener_ReduceCooldownOnDamage::OnDamageReceived(AActor* Target, AActor* Instigator, float Damage, const FHitResult& Hit) {
}

URPGAbilityEventListener_ReduceCooldownOnDamage::URPGAbilityEventListener_ReduceCooldownOnDamage() {
    this->bCheckSpellGroup = false;
    this->SpellGroupName = SOCIAL_SEMANTIC_DADA;
}

