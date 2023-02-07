#pragma once
#include "CoreMinimal.h"
#include "TypeWeight.generated.h"

USTRUCT(BlueprintType)
struct AIPATHSCHEDULER_API FTypeWeight {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float weight;
    
    FTypeWeight();
};

