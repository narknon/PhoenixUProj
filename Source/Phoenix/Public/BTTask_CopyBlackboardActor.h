#pragma once
#include "CoreMinimal.h"
#include "BTTask_CopyBlackboardValue.h"
#include "BTTask_CopyBlackboardActor.generated.h"

UCLASS(Blueprintable)
class UBTTask_CopyBlackboardActor : public UBTTask_CopyBlackboardValue {
    GENERATED_BODY()
public:
    UBTTask_CopyBlackboardActor();
};

