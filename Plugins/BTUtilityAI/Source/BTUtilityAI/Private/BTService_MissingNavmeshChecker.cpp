#include "BTService_MissingNavmeshChecker.h"

class AAIController;
class ANavigationData;

bool UBTService_MissingNavmeshChecker::HasNavmesh(const AAIController* AIOwner, const ANavigationData* NavData, const FVector Location, const FVector Extent, FVector& OutLocation) {
    return false;
}

UBTService_MissingNavmeshChecker::UBTService_MissingNavmeshChecker() {
    this->ErrorName = TEXT("MissingNavmeshChecker");
    this->HorzRadius = 500.00f;
    this->VertRadius = 500.00f;
}

