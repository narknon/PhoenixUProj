#pragma once
#include "CoreMinimal.h"
#include "ETimeDateChangeValueType.h"
#include "TimeDateChangeValue.generated.h"

USTRUCT(BlueprintType)
struct FTimeDateChangeValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETimeDateChangeValueType Type;
    
    DAYNIGHT_API FTimeDateChangeValue();
};

