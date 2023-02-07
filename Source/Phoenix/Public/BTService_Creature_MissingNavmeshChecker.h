#pragma once
#include "CoreMinimal.h"
#include "BTService_MissingNavmeshChecker.h"
#include "BTService_Creature_MissingNavmeshChecker.generated.h"

UCLASS(Blueprintable)
class UBTService_Creature_MissingNavmeshChecker : public UBTService_MissingNavmeshChecker {
    GENERATED_BODY()
public:
    UBTService_Creature_MissingNavmeshChecker();
};

