#pragma once
#include "CoreMinimal.h"
#include "AnimatedPropertyDriverBase.h"
#include "AnimatedIntegerPropertyDriver.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimatedIntegerPropertyDriver : public FAnimatedPropertyDriverBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DefaultValue;
    
    FAnimatedIntegerPropertyDriver();
};

