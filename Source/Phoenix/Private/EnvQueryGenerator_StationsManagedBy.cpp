#include "EnvQueryGenerator_StationsManagedBy.h"

UEnvQueryGenerator_StationsManagedBy::UEnvQueryGenerator_StationsManagedBy() {
    this->bUseAvailableStationsOnly = true;
    this->GenerateMaxCount = 20;
    this->SelectionMethod = EQS_SELECT_ALL;
}

