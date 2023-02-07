#include "SceneActionState_StitchingEnter.h"

USceneActionState_StitchingEnter::USceneActionState_StitchingEnter() {
    this->Path = NULL;
    this->AnimationComponent = NULL;
    this->Actor = NULL;
    this->EntryAnimSequence = NULL;
    this->CurrAnimSequence = NULL;
    this->PrevAnimSequence = NULL;
    this->AnimInstance = NULL;
    this->CCC = NULL;
    this->ShouldBeRegistered = false;
}

