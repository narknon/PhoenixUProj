#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "Engine/EngineTypes.h"
#include "BTDecorator_MovementMode.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_MovementMode : public UBTDecorator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<TEnumAsByte<EMovementMode>> MovementModes;
    
    UBTDecorator_MovementMode();
};

