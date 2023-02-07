#include "ForceRenderSettingsCommand.h"

FForceRenderSettingsCommand::FForceRenderSettingsCommand() {
    this->Scope = EForceRenderSettingsScope::OnPlay;
    this->bDisable = false;
}

