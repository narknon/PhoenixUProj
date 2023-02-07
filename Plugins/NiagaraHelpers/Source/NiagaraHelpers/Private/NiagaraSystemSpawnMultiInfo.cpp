#include "NiagaraSystemSpawnMultiInfo.h"

FNiagaraSystemSpawnMultiInfo::FNiagaraSystemSpawnMultiInfo() {
    this->SpawnRateCutoffPercentage = 0.00f;
    this->SpawnRateMethod = ENiagaraHelpersMultiSpawnRateType::DoNotCompute;
    this->bCombineBoundsAndMultiSpawnRates = false;
}

