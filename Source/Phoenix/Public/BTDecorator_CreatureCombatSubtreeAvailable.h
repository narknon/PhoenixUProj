#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_CreatureCombatSubtreeAvailable.generated.h"

class UCreatureCombatData;

UCLASS(Blueprintable)
class UBTDecorator_CreatureCombatSubtreeAvailable : public UBTDecorator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCreatureCombatData* CombatData;
    
    UBTDecorator_CreatureCombatSubtreeAvailable();
};

