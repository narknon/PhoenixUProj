#include "TutorialInfo.h"

FTutorialInfo::FTutorialInfo() {
    this->Modal = false;
    this->NonModalPosition = ETutorialPosition::Tutorial_TopLeft;
    this->DisplayTime = 0.00f;
    this->PressOrRelease = IE_Pressed;
    this->WaitForTaskCompleteMessage = false;
}

