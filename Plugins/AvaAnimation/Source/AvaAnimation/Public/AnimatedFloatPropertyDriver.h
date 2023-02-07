#pragma once
#include "CoreMinimal.h"
#include "AnimatedPropertyDriverBase.h"
#include "AnimatedFloatPropertyDriver.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimatedFloatPropertyDriver : public FAnimatedPropertyDriverBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultValue;
    
    FAnimatedFloatPropertyDriver();
};

