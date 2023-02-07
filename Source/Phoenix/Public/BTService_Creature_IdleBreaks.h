#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_Creature_IdleBreaks.generated.h"

UCLASS(Blueprintable)
class UBTService_Creature_IdleBreaks : public UBTService {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanUseIdleBreaks;
    
    UBTService_Creature_IdleBreaks();
};

