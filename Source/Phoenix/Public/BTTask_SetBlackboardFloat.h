#pragma once
#include "CoreMinimal.h"
#include "BTTask_SetBlackboardValue.h"
#include "BTTask_SetBlackboardFloat.generated.h"

UCLASS(Blueprintable)
class UBTTask_SetBlackboardFloat : public UBTTask_SetBlackboardValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UBTTask_SetBlackboardFloat();
};

