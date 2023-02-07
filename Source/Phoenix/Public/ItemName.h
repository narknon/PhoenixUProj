#pragma once
#include "CoreMinimal.h"
#include "ItemName.generated.h"

USTRUCT(BlueprintType)
struct FItemName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    PHOENIX_API FItemName();
};

