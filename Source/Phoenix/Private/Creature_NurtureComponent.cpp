#include "Creature_NurtureComponent.h"

bool UCreature_NurtureComponent::GetIsMale() const {
    return false;
}

bool UCreature_NurtureComponent::GetIsAlbino() const {
    return false;
}

UCreature_NurtureComponent::UCreature_NurtureComponent() {
    this->VariationData = NULL;
    this->bOverride_TameTargetPriorityWeight = false;
    this->TameTargetPriorityWeight = 0.50f;
    this->bOverride_TameTargetMode = false;
    this->TameTargetMode = ESocialCombatMode::AllModes;
    this->NurtureCalloutsSocket = TEXT("head");
    this->CreatureCharacter = NULL;
    this->LoadedAudioAsset = NULL;
}

