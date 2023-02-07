#pragma once
#include "CoreMinimal.h"
#include "BlendDomainIndoorsOutdoorsCurve.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct FBlendDomainIndoorsOutdoorsCurve {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* IndoorsOutdoorsCurve;
    
    RENDERSETTINGS_API FBlendDomainIndoorsOutdoorsCurve();
};

