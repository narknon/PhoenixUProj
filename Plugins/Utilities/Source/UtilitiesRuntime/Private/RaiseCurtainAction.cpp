#include "RaiseCurtainAction.h"

class UObject;
class URaiseCurtainAction;

URaiseCurtainAction* URaiseCurtainAction::RaiseCurtain(UObject* NewWhosAsking) {
    return NULL;
}

void URaiseCurtainAction::OnCurtainRaised() {
}

URaiseCurtainAction::URaiseCurtainAction() {
    this->CurtainSubsystem = NULL;
    this->WhosAsking = NULL;
}

