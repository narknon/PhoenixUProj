#include "Creature_CombatComponentV2.h"

class UCreature_AIComponent;

void UCreature_CombatComponentV2::OnCreatureAIStateChanged(UCreature_AIComponent* AIComponent, ECreatureAIState PrevAIState) {
}

int32 UCreature_CombatComponentV2::GetCurrentCombatStageIndex() const {
    return 0;
}

UCreature_CombatComponentV2::UCreature_CombatComponentV2() {
    this->ProgressionData = NULL;
    this->bStayInCombatDuringCinematic = false;
}

