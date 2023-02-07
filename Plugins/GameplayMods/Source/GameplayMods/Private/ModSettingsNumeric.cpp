#include "ModSettingsNumeric.h"

FModSettingsNumeric::FModSettingsNumeric() {
    this->CalculationType = EPropModCalculationType::Maximum;
    this->TimeBasedEffect = ETimeBasedEffectType::UnaffectedByTimeCurve;
    this->ExternalInputEffect = EInputModType::UnaffectedByExternalInput;
}

