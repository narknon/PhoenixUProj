#include "SanctuaryDesk.h"

class UPrimitiveComponent;

void ASanctuaryDesk::ClearPage(bool bFrontSide) {
}

void ASanctuaryDesk::BeginWritingPage() {
}

void ASanctuaryDesk::ApplyMaterialsToPaper(UPrimitiveComponent* InPaperComponent) {
}

ASanctuaryDesk::ASanctuaryDesk() {
    this->InkWritingMaterial = NULL;
    this->InkWritingBackSideMaterial = NULL;
    this->InkWritingCurve = NULL;
    this->FrontMaterialInstance = NULL;
    this->BackMaterialInstance = NULL;
}

