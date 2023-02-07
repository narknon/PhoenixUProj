#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_RunEQS.h"
#include "BTService_MissionACKEQS.generated.h"

UCLASS(Blueprintable)
class UBTService_MissionACKEQS : public UBTService_RunEQS {
    GENERATED_BODY()
public:
    UBTService_MissionACKEQS();
};

