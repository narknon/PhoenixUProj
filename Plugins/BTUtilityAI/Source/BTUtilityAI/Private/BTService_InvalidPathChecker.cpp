#include "BTService_InvalidPathChecker.h"
#include "Templates/SubclassOf.h"

class AAIController;
class ANavigationData;
class UNavigationQueryFilter;

bool UBTService_InvalidPathChecker::CanPath(const AAIController* AIOwner, const ANavigationData* NavData, const FVector From, const FVector To, TSubclassOf<UNavigationQueryFilter> QueryFilter, bool bAllowPartial, float ProjRadius, float ProjHeight) {
    return false;
}

UBTService_InvalidPathChecker::UBTService_InvalidPathChecker() {
    this->MaxChecksPerTick = 1;
    this->MaxCacheRefreshTime_Empty = 2.00f;
    this->MaxCacheRefreshTime_Valid = 10.00f;
    this->FilterClass = NULL;
    this->bDisallowPartial = true;
    this->ProjectionRadius = 100.00f;
    this->ProjectionHeight = 100.00f;
}

