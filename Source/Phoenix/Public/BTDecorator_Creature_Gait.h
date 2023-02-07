#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "ECreatureMovementSpeed.h"
#include "BTDecorator_Creature_Gait.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_Creature_Gait : public UBTDecorator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<ECreatureMovementSpeed> Gaits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowGaitTransition;
    
    UBTDecorator_Creature_Gait();
};

