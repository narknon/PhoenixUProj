#pragma once
#include "CoreMinimal.h"
#include "AblSuperSlamCurveData.generated.h"

class UCurveVector;

USTRUCT(BlueprintType)
struct FAblSuperSlamCurveData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveVector* Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInvertX;
    
    PHOENIX_API FAblSuperSlamCurveData();
};

