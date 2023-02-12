#pragma once
#include "CoreMinimal.h"
#include "AkWaapiFieldNames.generated.h"

USTRUCT(BlueprintType)
struct AKAUDIO_API FAkWaapiFieldNames {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString FieldName;
    
    FAkWaapiFieldNames();
};

