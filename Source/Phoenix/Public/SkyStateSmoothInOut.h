#pragma once
#include "CoreMinimal.h"
#include "SkyStateSmoothInOut.generated.h"

USTRUCT(BlueprintType)
struct FSkyStateSmoothInOut {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SmoothInTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SmoothOutTime;
    
    PHOENIX_API FSkyStateSmoothInOut();
};

