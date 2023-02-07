#include "DialogLineRule_CameraCharacter.h"

FDialogLineRule_CameraCharacter::FDialogLineRule_CameraCharacter() {
    this->PlacementTransform = NULL;
    this->OffsetFromDialogueLine = 0.00f;
    this->SwitchCameraLengthThreshold = 0.00f;
    this->UseWhenSpeaking = false;
    this->UseAtEnd = false;
    this->OffsetFromEnd = 0.00f;
    this->MinimumPreviousCameraLength = 0.00f;
}

