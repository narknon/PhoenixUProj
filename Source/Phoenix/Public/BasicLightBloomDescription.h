#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BasicLightBloomDescription.generated.h"

USTRUCT(BlueprintType)
struct FBasicLightBloomDescription {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BloomScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BloomThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor BloomTint;
    
    PHOENIX_API FBasicLightBloomDescription();
};

