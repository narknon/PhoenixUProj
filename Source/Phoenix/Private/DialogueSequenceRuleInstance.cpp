#include "DialogueSequenceRuleInstance.h"

FDialogueSequenceRuleInstance::FDialogueSequenceRuleInstance() {
    this->DSNode = NULL;
    this->CalledFromEditor = false;
    this->StopWhenAttachedToDestroyed = false;
    this->CreateTransformActions = false;
    this->CreateChracterOptions = false;
    this->AudioDialogueFlags = 0;
    this->CameraProxyActor = NULL;
    this->CameraActor = NULL;
}

