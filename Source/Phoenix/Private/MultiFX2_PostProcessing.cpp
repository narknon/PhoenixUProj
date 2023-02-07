#include "MultiFX2_PostProcessing.h"

UMultiFX2_PostProcessing::UMultiFX2_PostProcessing() {
    this->Definition = NULL;
    this->AutoBlendInTime = 1.00f;
    this->AutoBlendOutTime = 1.00f;
    this->DefaultBlendOutTime = 1.00f;
    this->bUseAutoBlendIn = false;
    this->bUseAutoBlendOut = false;
    this->Priority = 200.00f;
    this->IfAlreadyRunning = EFXPostProcessingDuplicateAction::Abort;
}

