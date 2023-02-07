#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_Creature_DesiredWorldDirection.generated.h"

UCLASS(Blueprintable)
class UBTService_Creature_DesiredWorldDirection : public UBTService {
    GENERATED_BODY()
public:
    UBTService_Creature_DesiredWorldDirection();
};

