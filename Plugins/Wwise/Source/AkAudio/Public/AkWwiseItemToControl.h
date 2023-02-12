#pragma once
#include "CoreMinimal.h"
#include "AkWwiseObjectDetails.h"
#include "AkWwiseItemToControl.generated.h"

USTRUCT(BlueprintType)
struct AKAUDIO_API FAkWwiseItemToControl {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAkWwiseObjectDetails ItemPicked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ItemPath;
    
    FAkWwiseItemToControl();
};

