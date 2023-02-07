#include "BentDirectionalLightWindow.h"

UBentDirectionalLightWindow::UBentDirectionalLightWindow() {
    this->TopBottomAngle = 30.00f;
    this->LeftRightAngle = 30.00f;
    this->CosineTopBottomAngle = 0.87f;
    this->CosineLeftRightAngle = 0.87f;
    this->WindowBaseAngle = 0.79f;
    this->bEnabled = true;
}

