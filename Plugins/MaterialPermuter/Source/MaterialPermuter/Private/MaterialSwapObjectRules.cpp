#include "MaterialSwapObjectRules.h"

FMaterialSwapObjectRules::FMaterialSwapObjectRules() {
    this->Rule = EMaterialSwapRulesObjects::Ignore;
    this->MatchMode = EMaterialSwapRulesObjectMatchMode::Exact;
}

