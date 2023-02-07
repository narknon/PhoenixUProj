#include "DLSSSettings.h"

UDLSSSettings::UDLSSSettings() {
    this->bEnableDLSSD3D12 = true;
    this->bEnableDLSSD3D11 = true;
    this->bEnableDLSSVulkan = true;
    this->bEnableDLSSInEditorViewports = true;
    this->bEnableScreenpercentageManipulationInDLSSEditorViewports = false;
    this->bEnableDLSSInPlayInEditorViewports = true;
    this->bShowDLSSSDebugOnScreenMessages = false;
    this->bGenericDLSSBinaryExists = false;
    this->NVIDIANGXApplicationId = 101174211;
    this->bCustomDLSSBinaryExists = false;
}

