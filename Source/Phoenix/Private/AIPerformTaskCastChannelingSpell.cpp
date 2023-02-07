#include "AIPerformTaskCastChannelingSpell.h"

void UAIPerformTaskCastChannelingSpell::DisillusionmentFinished(uint8 InAction) {
}

UAIPerformTaskCastChannelingSpell::UAIPerformTaskCastChannelingSpell() {
    this->ChannelingSpellType = EPerformTasksChannelingSpell::Lumos;
    this->bShouldStopChannelingSpell = false;
}

