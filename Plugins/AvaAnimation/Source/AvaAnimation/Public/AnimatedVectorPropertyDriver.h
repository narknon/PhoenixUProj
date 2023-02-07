#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AnimatedVectorPropertyDriver.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimatedVectorPropertyDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector DefaultValue;
    
    FAnimatedVectorPropertyDriver();
};

