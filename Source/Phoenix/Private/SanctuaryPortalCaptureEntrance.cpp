#include "SanctuaryPortalCaptureEntrance.h"

class UMaterialInstanceDynamic;

void ASanctuaryPortalCaptureEntrance::RuntimeReCapture() {
}

void ASanctuaryPortalCaptureEntrance::Capture() {
}

void ASanctuaryPortalCaptureEntrance::ApplyMaterialParameters(UMaterialInstanceDynamic* InMaterialInstanceDynamic) {
}

ASanctuaryPortalCaptureEntrance::ASanctuaryPortalCaptureEntrance() {
    this->RenderTarget = NULL;
    this->PreRenderedTexture = NULL;
    this->Exit = NULL;
    this->bReCaptureAtRuntime = false;
    this->bHasRuntimeCapture = false;
}

