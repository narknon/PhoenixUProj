#pragma once
#include "CoreMinimal.h"
#include "ItemInput.generated.h"

USTRUCT(BlueprintType)
struct FItemInput {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ItemId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ItemQuantity;
    
    PHOENIX_API FItemInput();
};

