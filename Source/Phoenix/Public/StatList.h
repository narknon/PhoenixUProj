#pragma once
#include "CoreMinimal.h"
#include "StatList.generated.h"

USTRUCT(BlueprintType)
struct FStatList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    PHOENIX_API FStatList();
};

