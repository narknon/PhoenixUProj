#pragma once
#include "CoreMinimal.h"
#include "BTTask_SetBlackboardValue.h"
#include "BTTask_SetBlackboardBool.generated.h"

UCLASS(Blueprintable)
class UBTTask_SetBlackboardBool : public UBTTask_SetBlackboardValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Value;
    
    UBTTask_SetBlackboardBool();
};

