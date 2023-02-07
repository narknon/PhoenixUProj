#include "AIPerformTaskCastSpell.h"

class AActor;

void UAIPerformTaskCastSpell::WeaponsAreReady(AActor* InActor) {
}

void UAIPerformTaskCastSpell::OnTargetActorSpawnInFinished(AActor* SpawnedActor) {
}

UAIPerformTaskCastSpell::UAIPerformTaskCastSpell() {
    this->SpellTargetActor = NULL;
    this->SpellType = EPerformTasksSpell::Reparo;
    this->CustomSpellAbility = NULL;
    this->CustomSpellToolRecord = NULL;
}

