#pragma once
#include "CoreMinimal.h"
#include "PointIndexes.generated.h"

USTRUCT(BlueprintType)
struct FPointIndexes {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> SampleIndexes;
    
    HOUDININIAGARA_API FPointIndexes();
};

