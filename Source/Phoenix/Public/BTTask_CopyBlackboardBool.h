#pragma once
#include "CoreMinimal.h"
#include "BTTask_CopyBlackboardValue.h"
#include "BTTask_CopyBlackboardBool.generated.h"

UCLASS(Blueprintable)
class UBTTask_CopyBlackboardBool : public UBTTask_CopyBlackboardValue {
    GENERATED_BODY()
public:
    UBTTask_CopyBlackboardBool();
};

