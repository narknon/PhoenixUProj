#pragma once
#include "CoreMinimal.h"
#include "AkBoolPropertyToControl.generated.h"

USTRUCT(BlueprintType)
struct AKAUDIO_API FAkBoolPropertyToControl {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ItemProperty;
    
    FAkBoolPropertyToControl();
};

