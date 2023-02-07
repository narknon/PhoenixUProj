#include "SceneAction_Sequence.h"

USceneAction_Sequence::USceneAction_Sequence() {
    this->Sequence = NULL;
    this->Looping = false;
    this->SequenceStart = 0.00f;
    this->SequenceFinish = 0.00f;
}

