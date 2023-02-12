#pragma once
#include "CoreMinimal.h"
#include "AkTriangle.generated.h"

USTRUCT(BlueprintType)
struct FAkTriangle {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint16 Point0;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint16 Point1;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint16 Point2;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint16 Surface;
    
    AKAUDIO_API FAkTriangle();
};

