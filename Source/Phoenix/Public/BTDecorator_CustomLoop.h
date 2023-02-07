#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_CustomLoop.generated.h"

class UBTDCustomLoopCount;

UCLASS(Blueprintable)
class UBTDecorator_CustomLoop : public UBTDecorator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBTDCustomLoopCount* LoopCount;
    
    UBTDecorator_CustomLoop();
};

