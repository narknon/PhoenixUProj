#include "RenderSettingsLibrary.h"

URenderSettingsLibrary::URenderSettingsLibrary() {
    this->PostProcessingPriorityBoost = 10000.00f;
    this->InsideTransitionDepth = 100.00f;
    this->AudioInsideTransitionDepth = 100.00f;
    this->IndoorsOutdoorsFiltering = 0.10f;
    this->IndoorsOutdoorsTeleportDistance = 200.00f;
    this->PostProcessingGroupSettings = NULL;
    this->ExposureSettings = NULL;
    this->ColorGradingSettings = NULL;
    this->FilmSettings = NULL;
    this->LensFXSettings = NULL;
    this->BloomSettings = NULL;
    this->MotionBlurSettings = NULL;
    this->DepthOfFieldSettings = NULL;
    this->AmbientSettings = NULL;
    this->ScreenSpaceReflectionsSettings = NULL;
    this->ProbeSettings = NULL;
    this->EmissiveAdaptationSettings = NULL;
    this->DistanceFogSettings = NULL;
    this->CharacterLightRigAdjustmentsSettings = NULL;
    this->GlobalBlendDomainConsoleVars = NULL;
    this->bGlobalDisableLevelDefaults = false;
    this->bPostProcessingPriorityBoost = false;
}

