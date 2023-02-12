#pragma once
#include "CoreMinimal.h"
#include "AkPropertyToControl.generated.h"

USTRUCT(BlueprintType)
struct AKAUDIO_API FAkPropertyToControl {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ItemProperty;
    
    FAkPropertyToControl();
};

