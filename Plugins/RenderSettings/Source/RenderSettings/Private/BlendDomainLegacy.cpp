#include "BlendDomainLegacy.h"

FBlendDomainLegacy::FBlendDomainLegacy() {
    this->IndoorsOutdoorsBlend = EBlendDomainIndoorsOutdoors::IndoorsAndOutdoors;
    this->IndoorsType = ERenderSettingsIndoorsType::Indoors;
    this->DayNightBlend = EBlendDomainDayNight::DayAndNight;
    this->OvercastClearBlend = EBlendDomainOvercast::ClearAndOvercast;
    this->LightingMode = EBlendDomainLightingMode::GameAndProbeCapture;
}

