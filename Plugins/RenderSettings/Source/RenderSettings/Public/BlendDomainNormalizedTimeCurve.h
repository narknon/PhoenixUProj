#pragma once
#include "CoreMinimal.h"
#include "BlendDomainNormalizedTimeCurve.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct FBlendDomainNormalizedTimeCurve {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* NormalizedTimeCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMirrorAroundNoon;
    
    RENDERSETTINGS_API FBlendDomainNormalizedTimeCurve();
};

