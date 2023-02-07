#include "SceneRigRule_DialogueSequence.h"

USceneRigRule_DialogueSequence::USceneRigRule_DialogueSequence() {
    this->DialogueSequenceReference = NULL;
    this->TemplateSceneRig = NULL;
    this->CreateTransformActions = false;
    this->CreateChracterOptions = false;
    this->Rule = NULL;
}

