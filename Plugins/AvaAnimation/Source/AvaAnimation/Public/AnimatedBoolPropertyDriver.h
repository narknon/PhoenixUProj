#pragma once
#include "CoreMinimal.h"
#include "AnimatedPropertyDriverBase.h"
#include "AnimatedBoolPropertyDriver.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimatedBoolPropertyDriver : public FAnimatedPropertyDriverBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DefaultValue;
    
    FAnimatedBoolPropertyDriver();
};

