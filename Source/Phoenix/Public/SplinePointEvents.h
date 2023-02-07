#pragma once
#include "CoreMinimal.h"
#include "SplinePointEvents.generated.h"

USTRUCT(BlueprintType)
struct FSplinePointEvents {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SplinePointIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> Events;
    
    PHOENIX_API FSplinePointEvents();
};

