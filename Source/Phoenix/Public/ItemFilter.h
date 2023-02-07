#pragma once
#include "CoreMinimal.h"
#include "ItemFilter.generated.h"

USTRUCT(BlueprintType)
struct FItemFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMatchesWholeWord;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Filter;
    
    PHOENIX_API FItemFilter();
};

