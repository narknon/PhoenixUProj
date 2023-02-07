#pragma once
#include "CoreMinimal.h"
#include "BTTask_SetBlackboardValue.h"
#include "BTTask_SetBlackboardInt.generated.h"

UCLASS(Blueprintable)
class UBTTask_SetBlackboardInt : public UBTTask_SetBlackboardValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    UBTTask_SetBlackboardInt();
};

