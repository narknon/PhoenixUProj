#pragma once
#include "CoreMinimal.h"
#include "BTTask_CopyBlackboardValue.h"
#include "BTTask_CopyBlackboardVector.generated.h"

UCLASS(Blueprintable)
class UBTTask_CopyBlackboardVector : public UBTTask_CopyBlackboardValue {
    GENERATED_BODY()
public:
    UBTTask_CopyBlackboardVector();
};

