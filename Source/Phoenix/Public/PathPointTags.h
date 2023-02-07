#pragma once
#include "CoreMinimal.h"
#include "PathPointTags.generated.h"

USTRUCT(BlueprintType)
struct FPathPointTags {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Tags;
    
    PHOENIX_API FPathPointTags();
};

