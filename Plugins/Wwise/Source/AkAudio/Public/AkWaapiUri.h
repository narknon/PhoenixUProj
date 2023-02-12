#pragma once
#include "CoreMinimal.h"
#include "AkWaapiUri.generated.h"

USTRUCT(BlueprintType)
struct AKAUDIO_API FAkWaapiUri {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Uri;
    
    FAkWaapiUri();
};

