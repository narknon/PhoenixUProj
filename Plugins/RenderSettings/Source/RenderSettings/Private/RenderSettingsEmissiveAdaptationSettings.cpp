#include "RenderSettingsEmissiveAdaptationSettings.h"

URenderSettingsEmissiveAdaptationSettings::URenderSettingsEmissiveAdaptationSettings() {
    this->AutoExposureBaseExpression = NULL;
    this->AverageLuminanceBaseExpression = NULL;
    this->FilteredAverageLuminanceBaseExpression = NULL;
    this->Settings.AddDefaulted(1);
}

