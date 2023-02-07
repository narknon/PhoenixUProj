#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_RunEQS.h"
#include "BTService_SocialActionWitnessEQS.generated.h"

UCLASS(Blueprintable)
class UBTService_SocialActionWitnessEQS : public UBTService_RunEQS {
    GENERATED_BODY()
public:
    UBTService_SocialActionWitnessEQS();
};

