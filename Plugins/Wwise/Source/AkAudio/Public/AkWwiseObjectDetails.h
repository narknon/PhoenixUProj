#pragma once
#include "CoreMinimal.h"
#include "AkWwiseObjectDetails.generated.h"

USTRUCT(BlueprintType)
struct AKAUDIO_API FAkWwiseObjectDetails {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ItemName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ItemPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ItemId;
    
    FAkWwiseObjectDetails();
};

