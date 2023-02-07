#pragma once
#include "CoreMinimal.h"
#include "InsideOfLevel.h"
#include "InsideOfLevelRanked.generated.h"

USTRUCT(BlueprintType)
struct FInsideOfLevelRanked : public FInsideOfLevel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Rank;
    
    CACHEDLEVELBOUNDS_API FInsideOfLevelRanked();
};

