#pragma once
#include "CoreMinimal.h"
#include "SplitWindow.generated.h"

USTRUCT(BlueprintType)
struct CONTROLMAPPER_API FSplitWindow {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float QueueOffsetTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bQueueStickDirection;
    
    FSplitWindow();
};

