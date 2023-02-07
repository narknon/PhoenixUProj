#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NavSlideInfo.generated.h"

USTRUCT(BlueprintType)
struct FNavSlideInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector BottomLinkEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TopLinkEnd;
    
    PHOENIX_API FNavSlideInfo();
};

