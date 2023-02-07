#pragma once
#include "CoreMinimal.h"
#include "DynamicSplineUsage.generated.h"

USTRUCT(BlueprintType)
struct FDynamicSplineUsage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Index;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 UsageFlags;
    
    DYNAMICSPLINESRUNTIME_API FDynamicSplineUsage();
};

