#include "RenderSettingsCustomBlendDomainRemap.h"

URenderSettingsCustomBlendDomainRemap::URenderSettingsCustomBlendDomainRemap() {
    this->domain = NULL;
    this->InputMin = 0.25f;
    this->InputMax = 0.75f;
    this->OunputMin = 0.00f;
    this->OutputMax = 1.00f;
}

