#pragma once
#include "CoreMinimal.h"
#include "BTTask_CopyBlackboardValue.h"
#include "BTTask_CopyBlackboardFloat.generated.h"

UCLASS(Blueprintable)
class UBTTask_CopyBlackboardFloat : public UBTTask_CopyBlackboardValue {
    GENERATED_BODY()
public:
    UBTTask_CopyBlackboardFloat();
};

