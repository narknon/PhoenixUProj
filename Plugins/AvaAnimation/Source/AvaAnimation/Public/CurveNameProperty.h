#pragma once
#include "CoreMinimal.h"
#include "CurveNameProperty.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FCurveNameProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CurveName;
    
    FCurveNameProperty();
};

