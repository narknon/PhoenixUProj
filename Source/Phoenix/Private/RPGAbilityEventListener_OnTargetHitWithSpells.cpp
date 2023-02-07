#include "RPGAbilityEventListener_OnTargetHitWithSpells.h"

class AActor;

void URPGAbilityEventListener_OnTargetHitWithSpells::OnDamageReceived(AActor* Target, AActor* Instigator, float Damage, const FHitResult& Hit) {
}

URPGAbilityEventListener_OnTargetHitWithSpells::URPGAbilityEventListener_OnTargetHitWithSpells() {
    this->TargetChainRule = HitTrackerTypes::Irrelevant;
    this->SpellChainRule = HitTrackerTypes::Irrelevant;
    this->bResetOnBeingHit = false;
    this->bResetOnFailedSpell = false;
    this->MaxTimeBetweenHits = 0.00f;
    this->bChanceBased = false;
    this->NumRequiredHits = 3;
    this->Wand = NULL;
}

