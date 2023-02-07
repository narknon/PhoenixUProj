#pragma once
#include "CoreMinimal.h"
#include "NpcTimer.generated.h"

USTRUCT(BlueprintType)
struct FNpcTimer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeStop;
    
    PHOENIX_API FNpcTimer();
};

