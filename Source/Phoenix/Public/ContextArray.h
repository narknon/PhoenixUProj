#pragma once
#include "CoreMinimal.h"
#include "InputContextWithType.h"
#include "ContextArray.generated.h"

USTRUCT(BlueprintType)
struct FContextArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInputContextWithType> Contexts;
    
    PHOENIX_API FContextArray();
};

