#pragma once
#include "CoreMinimal.h"
#include "CurveIndexProperty.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FCurveIndexProperty {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint16 CurveIndex;
    
    FCurveIndexProperty();
};

